#include "AtanorCountry.hpp"

int AtanorCountry::get_cost(const std::string& str) {
    int cost = 0;
    int idx = 0;
    while (std::isdigit(str[idx])) {
        cost *= 10;
        cost += str[idx] - '0';
        idx++;
    }

    return cost;
}

AtanorCountry::AtanorCountry(int id, const std::string& name,
                             const std::string& species, int money, int army,
                             int magic, int technology, int friendliness,
                             int resources, const std::string& topography,
                             const std::string& capital,
                             const std::string& description)
    : id_(id), name_(name), species_(species), money_(money), army_(army),
      magic_(magic), technology_(technology), friendliness_(friendliness),
      resources_(resources), topography_(topography), capital_(capital),
      description_(description) {}

AtanorCountry::AtanorCountry()
    : AtanorCountry(-1, "", "", 0, 0, 0, 0, 0, 0, "", "", "") {}

int AtanorCountry::get_id() { return id_; }

std::ostream& operator<<(std::ostream& os, const AtanorCountry& country) {
    os << country.name_ << ":\nРаса: " << country.species_
       << "\nДеньги: " << country.money_ << " pp\nВойско: " << country.army_
       << " pp\nМагия: " << country.magic_
       << " pp\nТехника: " << country.technology_
       << " pp\nДружба: " << country.friendliness_
       << " pp\nРесурсы: " << country.resources_
       << " pp\nМесто: " << country.topography_
       << "\nСтолица: " << country.capital_
       << "\nСуть: " << country.description_ << '\n';
    return os;
}
