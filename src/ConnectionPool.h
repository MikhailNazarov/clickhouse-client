#pragma once

#include "ConnectionOptions.h"
#include "Connection.h"
#include "utils/coro.h"

namespace Clickhouse {

    struct ConnectionPool {
        explicit ConnectionPool(ConnectionOptions options);

        awaitable<Connection> getConnection(bool auto_connect = true);
    private:
        ConnectionOptions options_;
    };
}


