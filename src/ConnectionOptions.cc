#include "ConnectionOptions.h"

namespace Clickhouse {
    ConnectionOptions ConnectionOptions::fromConnectionString(std::string_view connection_string) {
        return {}; //todo: parse options
    }

    ConnectionOptions::ConnectionOptions(std::string_view host, std::string_view user, std::string_view password,
                                         std::string_view database)
                                         :host{host},
                                          user{user},
                                          password{password},
                                          database{database}{

    }
}
