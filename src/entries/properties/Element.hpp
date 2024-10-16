#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>

class Element {
public:
    enum simple_element { AIR, WATER, EARTH, FIRE, LIFE, NONE, ANY };
    Element() = default;
    Element(simple_element e);
    Element(const std::string& raw);
    ~Element() = default;

    bool have(simple_element element);

    friend bool operator==(const Element& lhs, const Element& rhs);
    friend bool operator!=(const Element& lhs, const Element& rhs);

    friend std::ostream& operator<<(std::ostream& os, const Element& element);

private:
    static std::string to_string(simple_element e);

    std::vector<simple_element> elements;
};
