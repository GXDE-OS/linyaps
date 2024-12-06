// Thish file is generated by /tools/codegen
// DO NOT EDIT IT.

// clang-format off

//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     Linux.hpp data = nlohmann::json::parse(jsonString);

#pragma once

#include <optional>
#include <nlohmann/json.hpp>
#include "ocppi/runtime/features/types/helper.hpp"

#include "ocppi/runtime/features/types/Apparmor.hpp"
#include "ocppi/runtime/features/types/Cgroup.hpp"
#include "ocppi/runtime/features/types/IntelRdt.hpp"
#include "ocppi/runtime/features/types/Seccomp.hpp"
#include "ocppi/runtime/features/types/Selinux.hpp"

namespace ocppi {
namespace runtime {
namespace features {
namespace types {
enum class NamespaceType : int;
}
}
}
}

namespace ocppi {
namespace runtime {
namespace features {
namespace types {
/**
* Linux platform-specific features
*/

using nlohmann::json;

/**
* Linux platform-specific features
*/
struct Linux {
std::optional<Apparmor> apparmor;
std::optional<std::vector<std::string>> capabilities;
std::optional<Cgroup> cgroup;
std::optional<IntelRdt> intelRdt;
std::optional<std::vector<NamespaceType>> namespaces;
std::optional<Seccomp> seccomp;
std::optional<Selinux> selinux;
};
}
}
}
}

// clang-format on
