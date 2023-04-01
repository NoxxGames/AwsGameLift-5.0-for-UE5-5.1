/*
* All or portions of this file Copyright (c) Amazon.com, Inc. or its affiliates or
* its licensors.
*
* For complete copyright and license terms please see the LICENSE at the root of this
* distribution (the "License"). All use of this software is governed by the License,
* or, if provided, by the license below or the license accompanying this file. Do not
* remove or modify any license notices. This file is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*
*/
#pragma once

#include <thread>
#include <condition_variable>
#include <websocketpp/client.hpp>
#include <websocketpp/config/asio_client.hpp>
#include <aws/gamelift/internal/network/IWebSocketClientWrapper.h>

namespace Aws {
namespace GameLift {
namespace Internal {
    typedef websocketpp::client<websocketpp::config::asio_tls_client> WebSocketppClientType;

    /**
     * Implementation of a WebSocketClientWrapper for the Websocketpp Library.
     * https://github.com/zaphoyd/websocketpp
     */
    class WebSocketppClientWrapper : public IWebSocketClientWrapper {
    public:
        WebSocketppClientWrapper(std::shared_ptr<WebSocketppClientType> webSocketClient);

        Aws::GameLift::GenericOutcome Connect(const Uri &uri) override;
        Aws::GameLift::GenericOutcome SendSocketMessage(const std::string& requestId, const std::string& message) override;
        void Disconnect() override;
        void RegisterGameLiftCallback(const std::string& gameLiftEvent,
                const std::function<GenericOutcome(std::string)>& callback) override;
        bool IsConnected() override;

        ~WebSocketppClientWrapper();

    private:
        const int SERVICE_CALL_TIMEOUT_MILLIS = 20000;
        const int OK_STATUS_CODE = 200;

        // The WebSocketpp objects this class wraps
        std::shared_ptr<WebSocketppClientType> m_webSocketClient;
        WebSocketppClientType::connection_ptr m_connection;
        std::unique_ptr<std::thread> m_socket_thread_1;
        std::unique_ptr<std::thread> m_socket_thread_2;

        // synchronization variables
        std::mutex m_lock;
        std::condition_variable m_cond;
        bool m_connectionStateChanged;

        std::map<std::string, std::function<GenericOutcome(std::string)>> m_eventHandlers;
        std::mutex m_requestToPromiseLock;
        std::map<std::string, std::promise<GenericOutcome>> m_requestIdToPromise;

        // Helper methods
        WebSocketppClientType::connection_ptr PerformConnect(const Uri& uri);
        Aws::GameLift::GenericOutcome SendSocketMessageAsync(const std::string& message);

        // CallBacks
        void OnConnected(websocketpp::connection_hdl connection);
        void OnMessage(websocketpp::connection_hdl connection,
            websocketpp::config::asio_client::message_type::ptr msgPtr);
        websocketpp::lib::shared_ptr<asio::ssl::context> OnTlsInit(websocketpp::connection_hdl hdl);
        void OnClose(websocketpp::connection_hdl connection);
        void OnError(websocketpp::connection_hdl connection);
    };

} //namespace Internal
} //namespace GameLift
} //namespace Aws