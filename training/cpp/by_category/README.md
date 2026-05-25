# C++ By Category

This folder mirrors `training/python/by_category` with C++ solutions for the same interview problems.

Use these files after you understand the Python version. The goal is not to learn a different algorithm; it is to express the same algorithm with C++ syntax and STL containers.

## Structure

```text
training/cpp/by_category/
  1_array_hashmap/solutions/
  2_string/solutions/
  3_two_pointer_sliding_window/solutions/
  4_stack/solutions/
  5_tree_bfs/solutions/
  6_binary_search/solutions/
```

## Run One File

```bash
bash training/cpp/by_category/run_one.sh training/cpp/by_category/1_array_hashmap/solutions/p001_two_sum.cpp
```

The script compiles with `g++ -std=c++17` and runs the output binary from `/tmp`.

## Python to C++ Mental Mapping

| Algorithm concept | Python | C++ |
| --- | --- | --- |
| Dynamic array | `list` | `vector` |
| Hash map | `dict` | `unordered_map` |
| Hash set | `set` | `unordered_set` |
| Stack | `list` | `stack` or `vector` |
| Queue | `deque` | `queue` |
| Min heap | `heapq` | `priority_queue` with `greater<>` |
| Sort | `list.sort()` / `sorted()` | `sort(begin, end)` |
| Pair / coordinate | `tuple` | `pair` |

