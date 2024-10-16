#pragma once

#include <iostream>
#include <sqlite3.h>
#include <vector>

namespace dao {

template <typename E1, typename E2> class TransitiveDAO {
private:
    sqlite3* database;

protected:
    std::string entries_path;
    std::string table_name;

    sqlite3_stmt* get_prepared_statement(std::string sql);
    virtual bool fill_table() = 0;

public:
    TransitiveDAO(const std::string& db_path);

    virtual std::vector<E1> get_first(E2 second) = 0;
    virtual std::vector<E2> get_second(E1 first) = 0;

    virtual bool create_table() = 0;

    virtual ~TransitiveDAO() { sqlite3_close(database); }
};

template <typename E1, typename E2>
inline TransitiveDAO<E1, E2>::TransitiveDAO(const std::string& db_path) {
    int exit = sqlite3_open(db_path.c_str(), &database);

    if (exit != SQLITE_OK) {
        std::cerr << "Error open DB: " << sqlite3_errmsg(database) << std::endl;
        sqlite3_close(database);
    }
}

template <typename E1, typename E2>
inline sqlite3_stmt*
TransitiveDAO<E1, E2>::get_prepared_statement(std::string sql) {
    sqlite3_stmt* result_statement;
    const char* unused_sql_ptr;
    int exit = sqlite3_prepare_v2(database, sql.c_str(), sql.size(),
                                  &result_statement, &unused_sql_ptr);

    if (exit != SQLITE_OK) {
        std::cerr << "Error prepare statement: " << sqlite3_errmsg(database)
                  << '\n';
        return nullptr;
    }

    return result_statement;
}

} // namespace dao
