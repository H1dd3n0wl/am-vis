#include "AtanorCreatureCountryDAO.hpp"

namespace dao {

AtanorCreatureCountryDAO::AtanorCreatureCountryDAO(const std::string& db_path)
    : TransitiveDAO(db_path), creature_controller(db_path),
      country_controller(db_path) {
    table_name = "AtanorCreatureCountry";
    entries_path = std::string(ATANOR_ENTRIES_PATH) + "creature_country.csv";
}

std::vector<AtanorCreature>
AtanorCreatureCountryDAO::get_first(AtanorCountry second) {
    std::vector<AtanorCreature> result;

    std::stringstream query;
    query << "select * from " << table_name
          << " where country_id = " << second.get_id();
    auto prepared_statement = get_prepared_statement(query.str());

    int exit = sqlite3_step(prepared_statement);

    while (exit != SQLITE_DONE) {
        if (exit == SQLITE_ROW) {
            int creature_id = sqlite3_column_int(prepared_statement, 0);
            result.emplace_back(
                creature_controller.get_entity_by_id(creature_id));
        } else if (exit == SQLITE_ERROR) {
            std::cerr << "Error getting all\n";
            break;
        }
        exit = sqlite3_step(prepared_statement);
    }

    return result;
}

std::vector<AtanorCountry>
AtanorCreatureCountryDAO::get_second(AtanorCreature first) {
    std::vector<AtanorCountry> result;

    std::stringstream query;
    query << "select * from " << table_name
          << " where creature_id = " << first.get_id();
    auto prepared_statement = get_prepared_statement(query.str());

    int exit = sqlite3_step(prepared_statement);

    while (exit != SQLITE_DONE) {
        if (exit == SQLITE_ROW) {
            int country_id = sqlite3_column_int(prepared_statement, 1);
            result.emplace_back(
                country_controller.get_entity_by_id(country_id));
        } else if (exit == SQLITE_ERROR) {
            std::cerr << "Error getting all\n";
            break;
        }
        exit = sqlite3_step(prepared_statement);
    }

    return result;
}

bool AtanorCreatureCountryDAO::create_table() {

    auto check_existence_statement =
        get_prepared_statement(sql_tools::sql_check_existence(table_name));
    int exit = sqlite3_step(check_existence_statement);
    if (exit == SQLITE_ROW &&
        sqlite3_column_text(check_existence_statement, 0)) {
        return true;
    }

    std::stringstream query;
    query << "create table if not exists " << table_name
          << "(creature_id int not null, "
             "country_id int not null,"
             "foreign key(creature_id) references AtanorCreature(Id),"
             "foreign key(country_id) references AtanorCountry(Id));";

    auto create_statement = get_prepared_statement(query.str());
    if (sqlite3_step(create_statement) != SQLITE_DONE) {
        return false;
    }

    return fill_table();
}

bool AtanorCreatureCountryDAO::fill_table() {

    std::string qq = "insert into " + table_name + " values(1, 1);";

    int qex = sqlite3_step(get_prepared_statement(qq));
    std::cerr << qex << '\n';

    auto id_pairs = names_to_ids();

    for (auto [creature_id, country_id] : id_pairs) {
        std::stringstream query;
        query << "insert into " << table_name << " values(" << creature_id
              << ", " << country_id << ");";
        auto insert_stmt = get_prepared_statement(query.str());
        int exit = sqlite3_step(insert_stmt);

        if (exit == SQLITE_ERROR) {
            std::cerr << "Error occured inserting data\n";
        } else if (exit != SQLITE_OK) {
            // std::cerr << "Something else happened: exit code is " << exit << '\n';
        }
        exit = sqlite3_finalize(insert_stmt);
        // std::cerr << exit << '\n';
    }
    return true;
}

std::vector<std::pair<int, int>> AtanorCreatureCountryDAO::names_to_ids() {
    std::vector<std::pair<int, int>> ids;
    std::ifstream fin(entries_path);
    std::string data;
    std::getline(fin, data);

    while (std::getline(fin, data)) {
        std::size_t idx = std::find_if(std::begin(data), std::end(data),
                                       [](char ch) { return ch == ';'; }) -
                          std::begin(data);
        std::string name = data.substr(0, idx);
        std::string countries = data.substr(idx);
        if (countries == "Нейтрал") continue;

        int creature_id =
            creature_controller.get_entity_by_parameter("Название", name)
                .get_id();

        std::stringstream split_countries(countries);
        std::string country;
        while (std::getline(split_countries, country, ',')) {
            string_tools::trim(country);

            int country_id =
                country_controller.get_entity_by_parameter("Название", country)
                    .get_id();
            ids.emplace_back(creature_id, country_id);
        }
    }
    return ids;
}

} // namespace dao
