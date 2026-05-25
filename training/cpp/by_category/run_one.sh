#!/usr/bin/env bash
set -euo pipefail

if [ "$#" -ne 1 ]; then
  echo "Usage: bash training/cpp/by_category/run_one.sh path/to/file.cpp"
  exit 1
fi

src="$1"
out="/tmp/cpp_by_category_$(basename "$src" .cpp)"

g++ -std=c++17 -Wall -Wextra -pedantic "$src" -o "$out"
"$out"

