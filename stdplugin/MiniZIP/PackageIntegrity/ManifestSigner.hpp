#pragma once

#include <string>
#include <string_view>

namespace minizip::package_integrity {
class ManifestSigner {
public:
    virtual ~ManifestSigner() = default;
    virtual std::string sign(std::string_view manifest) const = 0;
    virtual bool verify(std::string_view manifest, std::string_view signature) const = 0;
};
} // namespace minizip::package_integrity
