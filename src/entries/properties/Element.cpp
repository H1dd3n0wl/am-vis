#include "Element.hpp"

Element::Element(simple_element e) { elements.push_back(e); }

Element::Element(const std::string& raw) {
    std::unordered_map<std::string, simple_element> mapping = {
        {"Воздух", simple_element::AIR}, {"Вода", simple_element::WATER},
        {"Огонь", simple_element::FIRE}, {"Земля", simple_element::EARTH},
        {"Жизнь", simple_element::LIFE}, {"Любая", simple_element::ANY},
        {"Нет", simple_element::NONE}};

    std::stringstream split(raw);
    std::string element;
    while (std::getline(split, element, '/')) {
        elements.emplace_back(mapping[element]);
    }
}

bool Element::have(simple_element element) {
    if (elements.empty()) {
        return false;
    }
    return elements[0] == simple_element::ANY ||
           std::find(std::begin(elements), std::end(elements), element) !=
               std::end(elements);
}

std::string Element::to_string(simple_element e) {
    switch (e) {
    case Element::simple_element::AIR:
        return "Воздух";
    case Element::simple_element::WATER:
        return "Вода";
    case Element::simple_element::FIRE:
        return "Огонь";
    case Element::simple_element::EARTH:
        return "Земля";
    case Element::simple_element::LIFE:
        return "Жизнь";
    case Element::simple_element::NONE:
        return "Нет";
    case Element::simple_element::ANY:
        return "Любая";
    default:
        return {};
    }
}

bool operator==(const Element& lhs, const Element& rhs) {
    return lhs.elements == rhs.elements;
}

bool operator!=(const Element& lhs, const Element& rhs) {
    return lhs.elements != rhs.elements;
}

std::ostream& operator<<(std::ostream& os, const Element& element) {
    for (std::size_t idx = 0; idx < element.elements.size() - 1; ++idx) {
        os << Element::to_string(element.elements[idx]) << ", ";
    }
    os << Element::to_string(element.elements.back());
    return os;
}
