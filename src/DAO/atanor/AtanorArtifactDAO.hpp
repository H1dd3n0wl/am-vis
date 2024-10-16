#pragma once

#include <AbstractDAO.hpp>
#include <AtanorArtifact.hpp>

namespace dao {

class AtanorArtifactDAO : public AbstractDAO<AtanorArtifact, int> {

    AtanorArtifact parse_row(sqlite3_stmt* statement);
    inline std::string get_create_table_query();

public:
    AtanorArtifactDAO(const std::string& db_path);
    ~AtanorArtifactDAO() = default;
};
} // namespace dao
