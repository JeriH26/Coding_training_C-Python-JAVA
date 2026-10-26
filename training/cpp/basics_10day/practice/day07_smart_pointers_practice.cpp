#include <cassert>
#include <iostream>
#include <memory>
#include <string>
#include <utility>

using namespace std;

/*
Practice Day 7

Only edit the TODO function body and TODO lines in main.
Goal: unique_ptr / shared_ptr / ownership.
*/

struct User {
    string name;
    explicit User(string user_name) : name(user_name) {}
};

int consume_user(unique_ptr<User> user) {
    // TODO: return the length of user's name.
    return static_cast<int>(user->name.size());
}

int main() {
    auto unique_owner = make_unique<User>("Ada");

    // TODO: move unique_owner into consume_user.
    int length = consume_user(std:: move(unique_owner));
    assert(length == 3);
    assert(unique_owner == nullptr);

    auto shared_a = make_shared<User>("Grace");
    // TODO: create shared_b as another shared_ptr to the same User.
    shared_ptr<User> shared_b = shared_a;

    assert(shared_a.use_count() == 2);
    assert(shared_b->name == "Grace");

    cout << "Day 7 practice passed\n";
    return 0;
}
