#pragma once

#include <algorithm>
#include <cctype>
#include <locale>
#include <string>
#include <regex>

namespace string_tools {

inline void ltrim(std::string& s) {
    s.erase(std::begin(s),
            std::find_if(std::begin(s), std::end(s),
                         [](char ch) { return !std::isspace(ch); }));
}

inline void rtrim(std::string& s) {
    s.erase(std::find_if(std::rbegin(s), std::rend(s),
                         [](char ch) { return !std::isspace(ch); })
                .base(),
            std::end(s));
}

inline void trim(std::string& s) {
    ltrim(s);
    rtrim(s);
}

} // namespace tools