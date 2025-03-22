// This file is generated by tools/codegen.sh
// DO NOT EDIT IT.

// clang-format off

//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     PackageManager1InstallParameters.hpp data = nlohmann::json::parse(jsonString);

#pragma once

#include <optional>
#include <nlohmann/json.hpp>
#include "linglong/api/types/v1/helper.hpp"

#include "linglong/api/types/v1/CommonOptions.hpp"
#include "linglong/api/types/v1/PackageManager1InstallParametersPacakge.hpp"

namespace linglong {
namespace api {
namespace types {
namespace v1 {
/**
* package manager install parameters
*/

using nlohmann::json;

/**
* package manager install parameters
*/
struct PackageManager1InstallParameters {
CommonOptions options;
PackageManager1InstallParametersPacakge package;
};
}
}
}
}

// clang-format on
