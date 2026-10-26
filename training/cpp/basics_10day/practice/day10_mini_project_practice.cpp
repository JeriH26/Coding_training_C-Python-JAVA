#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/*
Practice Day 10

Edit the TODO methods.
Goal: combine class, STL, const reference, and algorithms.
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
        // TODO: add only positive stock.
        if (amount >= 0){
            quantity_ += amount;
        }
    }

    bool remove_stock(int amount) {
        // TODO: remove only positive stock when enough quantity exists.
        if (amount <= 0 || quantity_ < amount){
            return false;
        }
        quantity_ -= amount;
        return true;
    }

    int total_value_cents() const {
        // TODO: quantity * price_cents.
        return quantity_ * price_cents_;
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
        // TODO: insert or replace item by SKU.
        items_.insert_or_assign(item.sku(), item);
    }

    bool add_stock(const string& sku, int amount) {
        // TODO: find item and add stock. Return false when SKU missing.
        auto it = items_.find(sku);
        if (it == items_.end()){
            return false;
        }

        it->second.add_stock(amount);
        return true;
    }

    bool remove_stock(const string& sku, int amount) {
        // TODO: find item and remove stock.
        auto it = items_.find(sku);
        if (it == items_.end()){
            return false;
        }

        return it->second.remove_stock(amount);

    }

    int quantity_of(const string& sku) const {
        // TODO: return quantity, or 0 if SKU is missing.
        auto it = items_.find(sku);
        if (it == items_.end()){
            return 0;
        }
        return it->second.quantity();
    }

    int total_inventory_value_cents() const {
        // TODO: sum each item's total value.
        int total = 0;
        for (const auto& entry : items_){
            total += entry.second.total_value_cents();
        }

        return total;
    }

    vector<Item> sorted_by_quantity_desc() const {
        // TODO: return items sorted by quantity from high to low.
        vector<Item> result;
        for (const auto& entry: items_){
            result.push_back(entry.second);
        }

        sort(result.begin(), result.end(), [](const Item& a, const Item& b){
            return a.name() < b.name();
        });

        return result;
    }

private:
    unordered_map<string, Item> items_;
};

int main() {
    Inventory inventory;
    inventory.add_item(Item("A100", "Keyboard", 5, 5000));
    inventory.add_item(Item("B200", "Mouse", 10, 2000));

    assert(inventory.quantity_of("A100") == 5);
    assert(inventory.add_stock("A100", 3));
    assert(inventory.quantity_of("A100") == 8);

    assert(inventory.remove_stock("B200", 4));
    assert(inventory.quantity_of("B200") == 6);
    assert(!inventory.remove_stock("B200", 999));

    assert(inventory.total_inventory_value_cents() == 52000);

    vector<Item> report = inventory.sorted_by_quantity_desc();
    assert(report.size() == 2);
    assert(report[0].sku() == "A100");
    assert(report[1].sku() == "B200");

    cout << "Day 10 practice passed\n";
    return 0;
}
