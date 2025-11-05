#ifndef STRING_UTILS_HPP
#define STRING_UTILS_HPP

#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <locale>
#include <sstream>

namespace string_utils {

std::string trim_left(const std::string& s) {
    std::string result = s;
    result.erase(result.begin(), std::find_if(result.begin(), result.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
    return result;
}

std::string trim_right(const std::string& s) {
    std::string result = s;
    result.erase(std::find_if(result.rbegin(), result.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), result.end());
    return result;
}

std::string trim(const std::string& s) {
    return trim_right(trim_left(s));
}

std::vector<std::string> split(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

std::string join(const std::vector<std::string>& v, const std::string& delimiter) {
    if (v.empty()) return "";
    std::string result = v[0];
    for (size_t i = 1; i < v.size(); ++i) {
        result += delimiter + v[i];
    }
    return result;
}

std::string to_upper(const std::string& s) {
    std::string result = s;
    std::transform(result.begin(), result.end(), result.begin(), [](unsigned char c) {
        return std::toupper(c);
    });
    return result;
}

std::string to_lower(const std::string& s) {
    std::string result = s;
    std::transform(result.begin(), result.end(), result.begin(), [](unsigned char c) {
        return std::tolower(c);
    });
    return result;
}

std::string replace_all(const std::string& s, const std::string& from, const std::string& to) {
    std::string result = s;
    size_t start_pos = 0;
    while ((start_pos = result.find(from, start_pos)) != std::string::npos) {
        result.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
    return result;
}

bool starts_with(const std::string& s, const std::string& prefix) {
    if (prefix.size() > s.size()) return false;
    return s.compare(0, prefix.size(), prefix) == 0;
}

bool ends_with(const std::string& s, const std::string& suffix) {
    if (suffix.size() > s.size()) return false;
    return s.compare(s.size() - suffix.size(), suffix.size(), suffix) == 0;
}

bool contains(const std::string& s, const std::string& substr) {
    return s.find(substr) != std::string::npos;
}

std::string pad_left(const std::string& s, size_t width, char pad_char = ' ') {
    if (s.size() >= width) return s;
    return std::string(width - s.size(), pad_char) + s;
}

std::string pad_right(const std::string& s, size_t width, char pad_char = ' ') {
    if (s.size() >= width) return s;
    return s + std::string(width - s.size(), pad_char);
}

std::string reverse(const std::string& s) {
    std::string result = s;
    std::reverse(result.begin(), result.end());
    return result;
}

size_t count(const std::string& s, const std::string& substr) {
    if (substr.empty()) return 0;
    size_t n = 0;
    size_t pos = 0;
    while ((pos = s.find(substr, pos)) != std::string::npos) {
        ++n;
        pos += substr.length();
    }
    return n;
}

}

#endif // STRING_UTILS_HPP