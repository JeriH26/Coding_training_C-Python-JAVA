#!/usr/bin/env bash
set -euo pipefail

if [ "$#" -ne 1 ]; then
  echo "Usage: bash training/cpp/basics_10day/run_practice.sh day01"
  echo "Example: bash training/cpp/basics_10day/run_practice.sh day04"
  exit 1
fi

day="$1"
src="$(find training/cpp/basics_10day/practice -maxdepth 1 -name "${day}_*.cpp" | head -n 1)"

if [ -z "$src" ]; then
  echo "No practice file found for: $day"
  exit 1
fi

name="$(basename "$src" .cpp)"
out="/tmp/cpp_basics_practice_${name}"

g++ -std=c++17 -Wall -Wextra -pedantic "$src" -o "$out"
"$out"

