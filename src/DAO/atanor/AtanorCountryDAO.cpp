#include "AtanorCountryDAO.hpp"

namespace dao {

AtanorCountryDAO::AtanorCountryDAO(const std::string& db_path)
    : AbstractDAO(db_path) {
    table_name = "AtanorCountry";
    entries_path = std::string(ATANOR_ENTRIES_PATH) + "fractions.csv";
}

AtanorCountry AtanorCountryDAO::parse_row(sqlite3_stmt* statement) {
    int id = sqlite3_column_int(statement, 0);
    std::string name =
        reinterpret_cast<const char*>(sqlite3_column_text(statement, 1));
    std::string species =
        reinterpret_cast<const char*>(sqlite3_column_text(statement, 2));
    int money = sqlite3_column_int(statement, 3);
    int army = sqlite3_column_int(statement, 4);
    int magic = sqlite3_column_int(statement, 5);
    int technology = sqlite3_column_int(statement, 6);
    int friendliness = sqlite3_column_int(statement, 7);
    int resources = sqlite3_column_int(statement, 8);
    std::string topography =
        reinterpret_cast<const char*>(sqlite3_column_text(statement, 9));
    std::string capital =
        reinterpret_cast<const char*>(sqlite3_column_text(statement, 10));
    std::string description =
        reinterpret_cast<const char*>(sqlite3_column_text(statement, 11));
    return AtanorCountry(id, name, species, money, army, magic, technology,
                         friendliness, resources, topography, capital,
                         description);
}

inline std::string AtanorCountryDAO::get_create_table_query() {
    return sql_tools::sql_create_table(
        table_name, "Название text", "Раса text", "Деньги int", "Войско int",
        "Магия int", "Техника int", "Дружба int", "Ресурсы int", "Место text",
        "Столица text", "Суть text");
}

} // namespace dao
