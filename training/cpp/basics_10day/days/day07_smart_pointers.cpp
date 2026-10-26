#include <cassert>
#include <iostream>
#include <memory>
#include <string>
#include <utility>

using namespace std;

/*
Day 7: unique_ptr / shared_ptr

Core idea:
- unique_ptr means exactly one owner.
- shared_ptr means multiple owners, tracked by a reference count.
- Prefer make_unique and make_shared.

Drills:
1. Move a unique_ptr into a function.
2. Create two shared_ptr variables pointing to the same object.
3. Explain when shared ownership is actually needed.
*/

struct User {
    string name;
    explicit User(string user_name) : name(user_name) {}
};

int name_length(unique_ptr<User> user) {
    return static_cast<int>(user->name.size());
}

int main() {
    auto owner = make_unique<User>("Ada");
    assert(owner->name == "Ada");

    int length = name_length(std::move(owner));
    assert(length == 3);
    assert(owner == nullptr);

    auto shared_a = make_shared<User>("Linus");
    shared_ptr<User> shared_b = shared_a;

    assert(shared_a.use_count() == 2);
    assert(shared_b->name == "Linus");

    cout << "shared count = " << shared_a.use_count() << "\n";
    cout << "Day 7 passed\n";
    return 0;
}
