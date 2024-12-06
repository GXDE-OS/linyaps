// This file is generated by tools/codegen.sh
// DO NOT EDIT IT.

// clang-format off

//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     ApplicationConfiguration.hpp data = nlohmann::json::parse(jsonString);

#pragma once

#include <optional>
#include <nlohmann/json.hpp>
#include "linglong/api/types/v1/helper.hpp"

#include "linglong/api/types/v1/ApplicationConfigurationPermissions.hpp"

namespace linglong {
namespace api {
namespace types {
namespace v1 {
/**
* application configuration
*/

using nlohmann::json;

/**
* application configuration
*/
struct ApplicationConfiguration {
std::optional<ApplicationConfigurationPermissions> permissions;
/**
* version of configuration file
*/
std::string version;
};
}
}
}
}

// clang-format on
