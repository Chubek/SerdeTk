#pragma once

#include "Checksum.hpp"
#include "MiniZIP-Plugin.hpp"

namespace minizip::package_integrity {
class Plugin final : public minizip::plugin::ArchivePlugin {
public:
    std::string_view id() const noexcept override { return "minizip.package-integrity"; }
    std::string_view version() const noexcept override { return "1.0.0"; }
    api::result<void> verify(const std::vector<api::listed_entry>& entries) const override {
        for (const auto& entry : entries) {
            if (entry.meta.logical_path.empty()) return api::result<void>("PackageIntegrity: empty entry path");
            if (entry.meta.kind == api::entry_kind::file && entry.meta.content_hash == 0)
                return api::result<void>("PackageIntegrity: missing content hash for " + entry.meta.logical_path);
        }
        return {};
    }
};
} // namespace minizip::package_integrity
