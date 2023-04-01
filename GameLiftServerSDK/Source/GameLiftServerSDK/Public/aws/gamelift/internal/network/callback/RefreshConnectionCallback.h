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

#include <aws/gamelift/internal/model/Message.h>
#include <aws/gamelift/internal/network/IGameLiftMessageHandler.h>
#include <aws/gamelift/common/Outcome.h>

namespace Aws {
namespace GameLift {
namespace Internal {
    /**
     * Class representing a default callback for RefreshConnectionMessage
     */
    class RefreshConnectionCallback {
    public:
        //Constructors
        RefreshConnectionCallback(IGameLiftMessageHandler *gameLiftMessageHandler) :
                m_gameLiftMessageHandler(gameLiftMessageHandler) {};

        ~RefreshConnectionCallback() = default;

        // Methods
        GenericOutcome OnRefreshConnection(const std::string& data);

        static constexpr const char* REFRESH_CONNECTION = "RefreshConnection";
        IGameLiftMessageHandler * m_gameLiftMessageHandler;
    };
}
}
}