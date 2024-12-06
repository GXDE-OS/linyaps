// This file is generated by tools/codegen.sh
// DO NOT EDIT IT.

// clang-format off

//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     ApplicationConfigurationPermissionsInnerBind.hpp data = nlohmann::json::parse(jsonString);

#pragma once

#include <optional>
#include <nlohmann/json.hpp>
#include "linglong/api/types/v1/helper.hpp"

namespace linglong {
namespace api {
namespace types {
namespace v1 {
/**
* items of inner binds of container
*/

using nlohmann::json;

/**
* items of inner binds of container
*/
struct ApplicationConfigurationPermissionsInnerBind {
/**
* mount source file to the another position of container
*/
std::string destination;
/**
* source file of container
*/
std::string source;
};
}
}
}
}

// clang-format on
