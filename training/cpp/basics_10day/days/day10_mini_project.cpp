#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/*
Day 10: mini project

Build a small inventory system using the previous 9 days.

Core idea:
- Use class to protect item data.
- Use unordered_map for lookup by SKU.
- Use vector + sort for reporting.
- Use const references to avoid copies.

Drills:
1. Add remove_stock.
2. Add total_inventory_value.
3. Print all items sorted by quantity descending.
*/

class Item {
public:
    Item(string sku, string name, int quantity, int price_cents)
        : sku_(sku), name_(name), quantity_(quantity), price_cents_(price_cents) {}

    const string& sku() const {
        return sku_;
    }

    const string& name() const {
        return name_;
    }

    int quantity() const {
        return quantity_;
    }

    int price_cents() const {
        return price_cents_;
    }

    void add_stock(int amount) {
        if (amount > 0) {
            quantity_ += amount;
        }
    }

private:
    string sku_;
    string name_;
    int quantity_;
    int price_cents_;
};

class Inventory {
public:
    void add_item(const Item& item) {
        items_.insert_or_assign(item.sku(), item);
    }

    bool add_stock(const string& sku, int amount) {
        auto it = items_.find(sku);
        if (it == items_.end()) {
            return false;
        }
        it->second.add_stock(amount);
        return true;
    }

    int quantity_of(const string& sku) const {
        auto it = items_.find(sku);
        if (it == items_.end()) {
            return 0;
        }
        return it->second.quantity();
    }

    vector<Item> sorted_by_name() const {
        vector<Item> result;
        for (const auto& entry : items_) {
            result.push_back(entry.second);
        }
        sort(result.begin(), result.end(), [](const Item& a, const Item& b) {
            return a.name() < b.name();
        });
        return result;
    }

private:
    unordered_map<string, Item> items_;
};

int main() {
    Inventory inventory;
    inventory.add_item(Item("A100", "Keyboard", 5, 4999));
    inventory.add_item(Item("B200", "Mouse", 10, 1999));

    assert(inventory.quantity_of("A100") == 5);
    assert(inventory.add_stock("A100", 3));
    assert(inventory.quantity_of("A100") == 8);
    assert(!inventory.add_stock("NOPE", 1));

    vector<Item> report = inventory.sorted_by_name();
    assert(report.size() == 2);
    assert(report[0].name() == "Keyboard");

    for (const Item& item : report) {
        cout << item.sku() << " " << item.name() << " qty=" << item.quantity() << "\n";
    }
    cout << "Day 10 passed\n";
    return 0;
}
