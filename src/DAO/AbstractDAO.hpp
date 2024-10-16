#pragma once

#include <fstream>
#include <iostream>
#include <iterator>
#include <sqlite3.h>
#include <sstream>
#include <string>
#include <tools/sql_tools.hpp>
#include <vector>

namespace dao {

template <typename E, typename K> class AbstractDAO {
private:
    sqlite3* database;

protected:
    std::string table_name;
    std::string entries_path;
    sqlite3_stmt* get_prepared_statement(std::string sql);
    virtual E parse_row(sqlite3_stmt* statement) = 0;
    inline virtual std::string get_create_table_query() = 0;
    virtual bool fill_table();

public:
    AbstractDAO(const std::string& db_path);

    std::vector<E> get_all();
    E get_entity_by_id(K id);
    template <typename Param>
    E get_entity_by_parameter(const std::string& parameter, Param value);
    bool create_table();

    virtual ~AbstractDAO() { sqlite3_close(database); };
};

template <typename E, typename K>
AbstractDAO<E, K>::AbstractDAO(const std::string& db_path) {
    int exit = sqlite3_open(db_path.c_str(), &database);

    if (exit != SQLITE_OK) {
        std::cerr << "Error open DB: " << sqlite3_errmsg(database) << std::endl;
        sqlite3_close(database);
    }
}

template <typename E, typename K>
sqlite3_stmt* AbstractDAO<E, K>::get_prepared_statement(std::string sql) {
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

template <typename E, typename K>
inline std::vector<E> AbstractDAO<E, K>::get_all() {
    std::vector<E> result;
    auto prepared_statement =
        get_prepared_statement(sql_tools::sql_select_all(table_name));
    int exit = sqlite3_step(prepared_statement);

    while (exit != SQLITE_DONE) {
        if (exit == SQLITE_ROW) {
            result.emplace_back(parse_row(prepared_statement));
        } else if (exit == SQLITE_ERROR) {
            std::cerr << "Error getting all\n";
            break;
        }
        exit = sqlite3_step(prepared_statement);
    }
    return result;
}

template <typename E, typename K>
inline E AbstractDAO<E, K>::get_entity_by_id(K id) {
    sqlite3_stmt* prepared_statement =
        get_prepared_statement(sql_tools::sql_select_by_id(table_name, id));

    int exit = sqlite3_step(prepared_statement);
    if (exit == SQLITE_ROW) {
        return parse_row(prepared_statement);
    } else if (exit == SQLITE_ERROR) {
        std::cerr << "Error getting entity\n";
    }
    return {};
}

template <typename E, typename K>
template <typename Param>
inline E
AbstractDAO<E, K>::get_entity_by_parameter(const std::string& parameter,
                                           Param value) {
    std::stringstream query;
    query << sql_tools::sql_select_all(table_name) << " where " << parameter
          << " = '" << value << "'";

    auto prepared_statement = get_prepared_statement(query.str());

    int exit = sqlite3_step(prepared_statement);
    if (exit == SQLITE_ROW) {
        return parse_row(prepared_statement);
        sqlite3_finalize(prepared_statement);
    } else if (exit == SQLITE_ERROR) {
        std::cerr << "Error getting entity\n";
    }
    sqlite3_finalize(prepared_statement);
    return {};
}

template <typename E, typename K>
inline bool AbstractDAO<E, K>::create_table() {
    auto check_existence_statement =
        get_prepared_statement(sql_tools::sql_check_existence(table_name));
    int exit = sqlite3_step(check_existence_statement);
    if (exit == SQLITE_ROW &&
        sqlite3_column_text(check_existence_statement, 0)) {
        return true;
    }

    auto create_statement = get_prepared_statement(get_create_table_query());
    if (sqlite3_step(create_statement) != SQLITE_DONE) {
        return false;
    }

    return fill_table();
}

template <typename E, typename K> inline bool AbstractDAO<E, K>::fill_table() {
    std::ifstream fin(entries_path);
    std::string line;
    std::getline(fin, line);
    int id_ = 1;
    while (std::getline(fin, line)) {
        auto insert_statement = get_prepared_statement(
            sql_tools::sql_insert(table_name, id_++, line));
        if (sqlite3_step(insert_statement) == SQLITE_ERROR) {
            std::cerr << "Error inserting data";
            return false;
        }
    }
    return true;
}

} // namespace dao
