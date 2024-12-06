#!/bin/bash

# SPDX-FileCopyrightText: 2023 UnionTech Software Technology Co., Ltd.
#
# SPDX-License-Identifier: LGPL-3.0-or-later

set -e
set -o pipefail

GIT=${GIT:="git"}

repoRoot="$("$GIT" rev-parse --show-toplevel)"
cd "$repoRoot/tools"

git submodule update --init --depth 1

QUICKTYPE=${QUICKTYPE:=$(command -v quicktype || true)}

if [ -z "$QUICKTYPE" ]; then
        pushd quicktype
        if not npx quicktype --version &>/dev/null; then
                npm i
                npm run build
        fi
        popd
fi

quicktype() {
        if [ -z "$QUICKTYPE" ]; then
                pushd quicktype
                npx quicktype "$@"
                popd
        else
                exec $QUICKTYPE "$@"
        fi
}

generate() {
        schema="$1"
        shift
        toplevel_type="$1"
        shift
        namespace="$1"
        shift
        include="$1"
        shift
        output_path="$1"

        if [[ ! -f "$schema" ]]; then
                echo "$schema not found" || exit 255
        fi

        filename="/dev/null"

        while read -r line; do
                if [[ $line != //\ stdout &&
                        $line != //*.hpp &&
                        $line != \#include\ \"*\" ]]; then
                        echo "$line" >>"$filename"
                        continue
                fi

                if [[ $line == \#include\ \"*\" ]]; then
                        header=${line#\#include\ \"}
                        header=${header%\"}
                        printf "#include \"%s/%s\"\n" \
                                "$output_path" \
                                "$header" \
                                >>"$filename"
                        continue
                fi

                echo "// clang-format on" >>"$filename"

                filename="${repoRoot}/$include/$output_path/${line#\/\/ }"
                if [[ $line == //\ stdout ]]; then
                        filename="/dev/null"
                fi

                # echo "generating $filename"

                mkdir -p "$(dirname "$filename")"
                {
                        echo "// This file is generated by tools/codegen.sh"
                        echo "// DO NOT EDIT IT."
                        echo ""
                        echo "// clang-format off"
                } >"$filename"
        done < <(quicktype "$schema" \
                --lang c++ \
                -s schema \
                -t "$toplevel_type" \
                --namespace "$namespace" \
                --code-format with-struct \
                --source-style multi-source \
                --include-location global-include \
                --type-style pascal-case-upper-acronyms \
                --member-style camel-case-upper-acronyms \
                --enumerator-style pascal-case-upper-acronyms \
                --no-boost \
                --hide-null-optional)

        {
                echo ""
                echo "// clang-format on"
        } >>"$filename"
}

# yq should use which written in go instead of python. https://github.com/mikefarah/yq
YQ=${YQ:=$(command -v yq)}

"$YQ" e '.properties = ( [
        .$defs | keys | .[] as $type | {
                "key" : $type,
                "value": {
                        "$ref": "#/$defs/"+$type
                }
        } ] | from_entries
)' "$repoRoot"/api/schema/v1.yaml -o json >"$repoRoot"/api/schema/v1.json

rm -f "$repoRoot"/libs/api/src/linglong/api/types/v1/*.hpp

generate \
        "$repoRoot/api/schema/v1.json" \
        LinglongAPIV1 \
        "linglong::api::types::v1" \
        "/libs/api/src/" \
        "linglong/api/types/v1"