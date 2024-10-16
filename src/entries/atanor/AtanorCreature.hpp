#pragma once

#include <tools/string_tools.hpp>

class AtanorCreature {
private:
    int id_;
    std::string name_;
    int level_;
    std::string drop_;
    std::string description_;

public:
    AtanorCreature(int id, const std::string& name, int level, const std::string& drop,
                   const std::string& description);
    AtanorCreature();
    ~AtanorCreature() = default;

    int get_id();

    friend std::ostream& operator<<(std::ostream& os, const AtanorCreature& creature);
};
