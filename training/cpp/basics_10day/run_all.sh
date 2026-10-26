#!/usr/bin/env bash
set -euo pipefail

root="training/cpp/basics_10day/days"

for src in "$root"/*.cpp; do
  name="$(basename "$src" .cpp)"
  out="/tmp/cpp_basics_${name}"
  echo "== $name =="
  g++ -std=c++17 -Wall -Wextra -pedantic "$src" -o "$out"
  "$out"
  echo
done

