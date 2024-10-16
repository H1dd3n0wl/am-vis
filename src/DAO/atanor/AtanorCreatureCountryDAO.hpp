#pragma once

#include <AtanorCountry.hpp>
#include <AtanorCountryDAO.hpp>
#include <AtanorCreature.hpp>
#include <AtanorCreatureDAO.hpp>
#include <TransitiveDAO.hpp>
#include <tools/string_tools.hpp>

namespace dao {

class AtanorCreatureCountryDAO
    : public TransitiveDAO<AtanorCreature, AtanorCountry> {

    AtanorCountryDAO country_controller;
    AtanorCreatureDAO creature_controller;

    bool fill_table();

    std::vector<std::pair<int, int>> names_to_ids();

public:
    AtanorCreatureCountryDAO(const std::string& db_path);

    std::vector<AtanorCreature> get_first(AtanorCountry second);
    std::vector<AtanorCountry> get_second(AtanorCreature first);

    bool create_table();

    ~AtanorCreatureCountryDAO() = default;
};

} // namespace dao