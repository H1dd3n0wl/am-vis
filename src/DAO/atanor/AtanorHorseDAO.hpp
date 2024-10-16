#pragma once

#include <AbstractDAO.hpp>
#include <AtanorHorse.hpp>

namespace dao {

class AtanorHorseDAO : public AbstractDAO<AtanorHorse, int> {

    AtanorHorse parse_row(sqlite3_stmt* statement);
    inline std::string get_create_table_query();

public:
    AtanorHorseDAO(const std::string& db_path);
    ~AtanorHorseDAO() = default;
};

} // namespace dao