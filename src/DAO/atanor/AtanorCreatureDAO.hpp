#pragma once

#include <AbstractDAO.hpp>
#include <AtanorCreature.hpp>

namespace dao {

class AtanorCreatureDAO : public AbstractDAO<AtanorCreature, int> {

    AtanorCreature parse_row(sqlite3_stmt* statement);
    inline std::string get_create_table_query();

public:
    AtanorCreatureDAO(const std::string& db_path);
    ~AtanorCreatureDAO() = default;
};

} // namespace dao