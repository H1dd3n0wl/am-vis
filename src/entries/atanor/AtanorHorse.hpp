#pragma once

#include <Element.hpp>
#include <ItemRarity.hpp>
#include <optional>
#include <sstream>

class AtanorHorse {
private:
    int id_;
    std::string name_;
    std::optional<int> cost_;
    Element element_;
    ItemRarity rarity_;
    std::string description_;

public:
    AtanorHorse(int id, const std::string& name, int cost,
                const Element& element, const ItemRarity& rarity,
                const std::string& description);
    AtanorHorse();
    ~AtanorHorse() = default;

    int get_id();

    friend std::ostream& operator<<(std::ostream& os, const AtanorHorse& horse);
};
