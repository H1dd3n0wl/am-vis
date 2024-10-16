#include "AtanorCreatureDAO.hpp"

namespace dao {

AtanorCreatureDAO::AtanorCreatureDAO(const std::string& db_path)
    : AbstractDAO(db_path) {
    table_name = "AtanorCreature";
    entries_path = std::string(ATANOR_ENTRIES_PATH) + "creatures.csv";
}

AtanorCreature AtanorCreatureDAO::parse_row(sqlite3_stmt* statement) {
    int id = sqlite3_column_int(statement, 0);
    std::string name =
        reinterpret_cast<const char*>(sqlite3_column_text(statement, 1));
    int level = sqlite3_column_int(statement, 2);
    std::string drop =
        reinterpret_cast<const char*>(sqlite3_column_text(statement, 3));
    std::string description =
        reinterpret_cast<const char*>(sqlite3_column_text(statement, 4));

    return AtanorCreature(id, name, level, drop, description);
}

inline std::string AtanorCreatureDAO::get_create_table_query() {
    return sql_tools::sql_create_table(table_name, "Название text",
                                       "Уровень int", "Дроп text", "Суть text");
}

} // namespace dao