#include "ItemRarity.hpp"

ItemRarity::ItemRarity(Value rarity) : value(rarity) {}

ItemRarity::ItemRarity(const std::string& rarity) {

    std::unordered_map<std::string, Value> mapping = {
        {"Обычная", Value::USUAL},       {"Редкая", Value::RARE},
        {"Эпическая", Value::EPIC},      {"Легендарная", Value::LEGENDARY},
        {"Мифическая", Value::MYTHICAL}, {"Единственная", Value::UNIQUE}};

    if (!mapping.contains(rarity.substr(0, rarity.find(' ')))) {
        value = Value::UNDEFINED;
    }

    value = mapping[rarity.substr(0, rarity.find(' '))];
}

constexpr bool ItemRarity::operator==(const ItemRarity& other) const {
    return value == other.value;
}

constexpr bool ItemRarity::operator!=(const ItemRarity& other) const {
    return value != other.value;
}

std::string ItemRarity::to_string() const {
    switch (value) {
    case USUAL:
        return "Обычная";
    case RARE:
        return "Редкая";
    case EPIC:
        return "Эпическая";
    case LEGENDARY:
        return "Легендарная";
    case MYTHICAL:
        return "Мифическая";
    case UNIQUE:
        return "Единственная";
    default:
        return "UNDEFINED";
    }
}

std::ostream& operator<<(std::ostream& os, const ItemRarity& rarity) {
    os << rarity.to_string();
    return os;
}
