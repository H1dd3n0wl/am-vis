#pragma once

#include <AbstractDAO.hpp>
#include <AtanorCountry.hpp>

namespace dao {

class AtanorCountryDAO : public AbstractDAO<AtanorCountry, int> {

    AtanorCountry parse_row(sqlite3_stmt* statement);
    inline std::string get_create_table_query();

public:
    AtanorCountryDAO(const std::string& db_path);
    ~AtanorCountryDAO() = default;
};

} // namespace dao
