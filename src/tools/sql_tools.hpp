#pragma once

#include <sstream>
#include <string>
#include <vector>

namespace sql_tools {

inline std::string sql_select_all(const std::string& table_name) {
    return "select * from " + table_name;
}

inline std::string sql_select_by_id(const std::string& table_name, int id) {
    std::stringstream result_query;
    result_query << "select * from " << table_name << " where Id = " << id;
    return result_query.str();
}

inline std::string sql_check_existence(const std::string& table_name) {
    return "select * from sqlite_master where type = 'table' and name = '" +
           table_name + "'";
}

template <typename... Args>
inline std::string sql_create_table(const std::string& table_name,
                                    Args... args) {
    std::stringstream result_query;
    result_query << "create table if not exists " << table_name
                 << "(Id int not null primary key";
    std::vector<std::string> arguments = {args...};
    for (auto arg : arguments) {
        result_query << ", " << arg << " not null";
    }
    result_query << ");";
    return result_query.str();
}

inline std::string sql_insert(const std::string& table_name, int id,
                              const std::string& values) {
    std::stringstream result_query;
    std::stringstream split_values(values);
    result_query << "insert into " << table_name << " values(" << id;
    std::string value;
    while (std::getline(split_values, value, ';')) {
        result_query << ", '" << value << "'";
    }
    result_query << ");";
    return result_query.str();
}

} // namespace sql_tools