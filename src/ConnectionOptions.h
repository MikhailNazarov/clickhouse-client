#pragma once
#include <string>
#include <optional>
#include <vector>
#include <cstdint>
#include <chrono>

namespace Clickhouse {
    enum class Compression{
        kNone = 0,
        kLz4  = 1,
    };

    enum class Mode{
        kWriteAll = 0,
        kReadOnly = 1,
        kReadOnlyAndSettingsWrite = 2,
    };

/*
     ConnectionString:
        schema://user:password@host[:port]/database?param1=value1&...&paramN=valueN
     example:
        tcp://user:password@host:9000/clicks?compression=lz4&ping_timeout=42ms

        compression - Whether or not use compression (defaults to none). Possible choices:

            none
            lz4
        readonly - Restricts permissions for read data, write data and change settings queries. (defaults to none). Possible choices:

            0 - All queries are allowed.
            1 - Only read data queries are allowed.
            2 - Read data and change settings queries are allowed.
        connection_timeout - Timeout for connection (defaults to 500 ms)

        query_timeout - Timeout for queries (defaults to 180 sec).

        insert_timeout - Timeout for inserts (defaults to 180 sec).

        execute_timeout - Timeout for execute (defaults to 180 sec).

        keepalive - TCP keep alive timeout in milliseconds.

        nodelay - Whether to enable TCP_NODELAY (defaults to true).

        pool_min - Lower bound of opened connections for Pool (defaults to 10).

        pool_max - Upper bound of opened connections for Pool (defaults to 20).

        ping_before_query - Ping server every time before execute any query. (defaults to true).

        send_retries - Count of retry to send request to server. (defaults to 3).

        retry_timeout - Amount of time to wait before next retry. (defaults to 5 sec).

        ping_timeout - Timeout for ping (defaults to 500 ms).

        alt_hosts - Comma separated list of single address host for load-balancing.
     */
    struct ConnectionOptions {
        using MilliSeconds = std::chrono::milliseconds;
        using Seconds = std::chrono::seconds;

        std::string user{"default"};
        std::string password;
        std::string host;
        std::vector<std::string> alt_hosts{};
        uint16_t port{9000};
        std::optional<std::string> database;
        Compression compression {Compression::kNone};
        Mode mode{Mode::kWriteAll};

        MilliSeconds connection_timeout = MilliSeconds{500};
        MilliSeconds query_timeout = Seconds{180};
        MilliSeconds insert_timeout = Seconds{180};
        MilliSeconds execute_timeout = Seconds{180};
        MilliSeconds keep_alive{0};
        MilliSeconds retry_timeout = Seconds{5};
        MilliSeconds ping_timeout = MilliSeconds{500};

        bool no_delay = true;
        uint16_t pool_min = 10;
        uint16_t pool_max = 20;
        bool ping_before_query = true;

        ConnectionOptions() = default;
        ConnectionOptions(std::string_view host, std::string_view user, std::string_view password, std::string_view database = "default");
        static ConnectionOptions fromConnectionString(std::string_view connection_string);

    };
}


