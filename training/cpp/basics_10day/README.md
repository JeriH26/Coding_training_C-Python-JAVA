# C++ Basics 10-Day Training

这套训练对应你列出的 10 天基础路线。目标不是背语法，而是能读懂、能改、能解释、能用 C++ 写小型问题。

原始路线：Day 1 到 Day 10 覆盖 variable/function/scope、STL、指针引用、class、RAII、智能指针、现代 C++ 和 STL algorithm。:codex-annotation{index="1"}

## How to Run

Run all solution/demo files:

```bash
bash training/cpp/basics_10day/run_all.sh
```

Run one day:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic training/cpp/basics_10day/days/day01_basics_control.cpp -o /tmp/day01
/tmp/day01
```

Run one practice file:

```bash
bash training/cpp/basics_10day/run_practice.sh day01
```

The practice files live in:

```text
training/cpp/basics_10day/practice/
```

They intentionally contain TODO implementations. Your job is to edit only the TODO parts, run the file, read the failed `assert`, then fix it until the file prints `practice passed`.

## Training Rules

1. Read the matching demo file in `days/`.
2. Run the demo file once without editing.
3. Explain the output in your own words.
4. Open the matching practice file in `practice/`.
5. Fill in TODO code.
6. Re-run until the program compiles cleanly and all `assert` checks pass.

## 10-Day Plan

| Day | File | Must Master | You should be able to explain |
| --- | --- | --- | --- |
| 1 | `day01_basics_control.cpp` | variable, function, scope, `if`, `for`, `while` | local variables, return values, loop conditions |
| 2 | `day02_vector_string.cpp` | `vector`, `string`, range-for | dynamic arrays, indexing, push/pop, string traversal |
| 3 | `day03_maps_sets.cpp` | `unordered_map`, `map`, `set` | hash lookup vs ordered traversal, counting frequency |
| 4 | `day04_memory_reference_pointer.cpp` | stack, heap, pointer, reference | address, dereference, pass by value/reference |
| 5 | `day05_class_constructor.cpp` | `class`, constructor, public/private | object state, methods, invariants |
| 6 | `day06_raii_destructor.cpp` | RAII, lifetime, destructor | constructor acquires, destructor releases |
| 7 | `day07_smart_pointers.cpp` | `unique_ptr`, `shared_ptr` | ownership, move, reference count |
| 8 | `day08_modern_cpp.cpp` | `auto`, `const`, lambda | type inference, immutability, small callable functions |
| 9 | `day09_stl_algorithms.cpp` | `sort`, `find`, `lower_bound` | iterator ranges, sorted precondition |
| 10 | `day10_mini_project.cpp` | integration | build a small command-line inventory system |

## Daily Output Requirement

After each day, write a short note:

```text
Day:
What I learned:
One bug I hit:
One concept I can explain:
One concept still unclear:
```

## Fast Review Questions

- What is the difference between `int x`, `int& r`, and `int* p`?
- Why should most C++ code avoid raw `new` and `delete`?
- When should you use `vector` instead of `map`?
- Why does `lower_bound` require sorted data?
- What resource does your Day 6 RAII object own?
