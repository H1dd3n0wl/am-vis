#include <AtanorArtifactDAO.hpp>

namespace dao {

AtanorArtifactDAO::AtanorArtifactDAO(const std::string& db_path)
    : AbstractDAO(db_path) {
    table_name = "AtanorArtifact";
    entries_path = std::string(ATANOR_ENTRIES_PATH) + "artifacts.csv";
}

AtanorArtifact AtanorArtifactDAO::parse_row(sqlite3_stmt* statement) {
    int id = sqlite3_column_int(statement, 0);
    std::string name =
        reinterpret_cast<const char*>(sqlite3_column_text(statement, 1));
    ArtifactSlot slot(
        reinterpret_cast<const char*>(sqlite3_column_text(statement, 2)));
    ItemRarity rarity(
        reinterpret_cast<const char*>(sqlite3_column_text(statement, 3)));
    std::string description =
        reinterpret_cast<const char*>(sqlite3_column_text(statement, 4));
    return AtanorArtifact(id, name, slot, rarity, description);
}

inline std::string AtanorArtifactDAO::get_create_table_query() {
    return sql_tools::sql_create_table(table_name, "Название text", "Слот text",
                                       "Редкость text", "Суть text");
}

} // namespace dao
