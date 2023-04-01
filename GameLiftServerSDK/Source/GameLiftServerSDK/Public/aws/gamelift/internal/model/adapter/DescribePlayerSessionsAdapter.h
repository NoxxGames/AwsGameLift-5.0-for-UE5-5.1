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

#include <aws/gamelift/server/model/DescribePlayerSessionsResult.h>
#include <aws/gamelift/server/model/DescribePlayerSessionsRequest.h>
#include <aws/gamelift/internal/model/response/WebSocketDescribePlayerSessionsResponse.h>
#include <aws/gamelift/internal/model/request/WebSocketDescribePlayerSessionsRequest.h>

namespace Aws {
namespace GameLift {
namespace Internal {
    class DescribePlayerSessionsAdapter {
    public:
        static Server::Model::DescribePlayerSessionsResult convert(const WebSocketDescribePlayerSessionsResponse* webSocketResponse);
        static WebSocketDescribePlayerSessionsRequest convert(const Server::Model::DescribePlayerSessionsRequest& request);
    };
}
}
}