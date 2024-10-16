#include "AtanorHorse.hpp"

AtanorHorse::AtanorHorse(int id, const std::string& name, int cost,
                         const Element& element, const ItemRarity& rarity,
                         const std::string& description)
    : id_(id), name_(name),
      cost_(cost > 0 ? std::optional<int>(cost) : std::nullopt),
      element_(element), rarity_(rarity), description_(description) {}

AtanorHorse::AtanorHorse()
    : AtanorHorse(-1, "", 0, Element::NONE, ItemRarity::UNDEFINED, "") {}

int AtanorHorse::get_id() { return id_; }

std::ostream& operator<<(std::ostream& os, const AtanorHorse& horse) {
    os << horse.name_ << ":\nСтоимость: ";
    if (horse.cost_) {
        os << horse.cost_.value() << " pp";
    } else {
        os << "Не продается";
    }
    os << "\nСтихия: " << horse.element_ << "\nЛегендарность: " << horse.rarity_
       << "\nСуть: " << horse.description_;
    return os;
}
