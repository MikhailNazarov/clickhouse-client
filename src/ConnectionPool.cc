#include "ConnectionPool.h"


namespace Clickhouse{

    ConnectionPool::ConnectionPool(ConnectionOptions options): options_{std::move(options)}{

    }

    awaitable<Connection> ConnectionPool::getConnection(bool auto_connect) {
        co_return Connection();
    }
}