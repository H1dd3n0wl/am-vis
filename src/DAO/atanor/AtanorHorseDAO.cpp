#include "AtanorHorseDAO.hpp"

namespace dao {

AtanorHorseDAO::AtanorHorseDAO(const std::string& db_path)
    : AbstractDAO(db_path) {
    table_name = "AtanorHorse";
    entries_path = std::string(ATANOR_ENTRIES_PATH) + "horses.csv";
}

AtanorHorse AtanorHorseDAO::parse_row(sqlite3_stmt* statement) {
    int id = sqlite3_column_int(statement, 0);
    std::string name =
        reinterpret_cast<const char*>(sqlite3_column_text(statement, 1));
    int cost = sqlite3_column_int(statement, 2);
    Element elements(
        reinterpret_cast<const char*>(sqlite3_column_text(statement, 3)));
    ItemRarity rarity(
        reinterpret_cast<const char*>(sqlite3_column_text(statement, 4)));
    std::string description =
        reinterpret_cast<const char*>(sqlite3_column_text(statement, 5));

    return AtanorHorse(id, name, cost, elements, rarity, description);
}

inline std::string AtanorHorseDAO::get_create_table_query() {
    return sql_tools::sql_create_table(table_name, "Название text",
                                       "Стоимость int", "Стихия text",
                                       "Редкость text", "Суть text");
}

} // namespace dao
