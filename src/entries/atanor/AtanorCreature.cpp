#include "AtanorCreature.hpp"

AtanorCreature::AtanorCreature(int id, const std::string& name, int level,
                               const std::string& drop,
                               const std::string& description)
    : id_(id), name_(name), level_(level), drop_(drop),
      description_(description) {}

AtanorCreature::AtanorCreature() : AtanorCreature(-1, "", 0, "", "") {}

int AtanorCreature::get_id() { return id_; }

std::ostream& operator<<(std::ostream& os, const AtanorCreature& creature) {
    os << creature.name_ << ":\n"
       << "Уровень: " << creature.level_ << "\nДроп: " << creature.drop_
       << "\nСуть: " << creature.description_ << '\n';
    return os;
}
