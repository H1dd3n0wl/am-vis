#pragma once

#include <iostream>
#include <string>
#include <unordered_map>

class ItemRarity {
public:
    enum Value { USUAL, RARE, EPIC, LEGENDARY, MYTHICAL, UNIQUE, UNDEFINED };
    ItemRarity() = default;
    ItemRarity(Value rarity);
    ItemRarity(const std::string& rarity);
    ~ItemRarity() = default;

    constexpr bool operator==(const ItemRarity& other) const;
    constexpr bool operator!=(const ItemRarity& other) const;

    friend std::ostream& operator<<(std::ostream& os, const ItemRarity& rarity);

private:
    std::string to_string() const;

    Value value = Value::UNDEFINED;
};