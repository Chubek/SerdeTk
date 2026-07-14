#pragma once

#include "MiniZIP.hpp"

#include <string>
#include <string_view>

namespace minizip::package_integrity {
inline std::string checksum(std::string_view value) {
    return std::to_string(detail::fnv1a64(value));
}
} // namespace minizip::package_integrity
