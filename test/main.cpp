#include "../include/string_utils.hpp"
#include <iostream>
#include <cassert>

int main() {
    // Test trim_left
    {
        std::string input = "   hello world";
        std::string expected = "hello world";
        std::string result = string_utils::trim_left(input);
        if (result != expected) {
            std::cout << "trim_left failed: expected '" << expected << "', got '" << result << "'" << std::endl;
            return 1;
        }
    }

    // Test trim_right
    {
        std::string input = "hello world   ";
        std::string expected = "hello world";
        std::string result = string_utils::trim_right(input);
        if (result != expected) {
            std::cout << "trim_right failed: expected '" << expected << "', got '" << result << "'" << std::endl;
            return 1;
        }
    }

    // Test trim
    {
        std::string input = "   hello world   ";
        std::string expected = "hello world";
        std::string result = string_utils::trim(input);
        if (result != expected) {
            std::cout << "trim failed: expected '" << expected << "', got '" << result << "'" << std::endl;
            return 1;
        }
    }

    // Test split
    {
        std::string input = "a,b,c";
        std::vector<std::string> expected = {"a", "b", "c"};
        std::vector<std::string> result = string_utils::split(input, ',');
        if (result != expected) {
            std::cout << "split failed" << std::endl;
            return 1;
        }
    }

    // Test join
    {
        std::vector<std::string> input = {"a", "b", "c"};
        std::string expected = "a-b-c";
        std::string result = string_utils::join(input, "-");
        if (result != expected) {
            std::cout << "join failed: expected '" << expected << "', got '" << result << "'" << std::endl;
            return 1;
        }
    }

    // Test to_upper
    {
        std::string input = "hello";
        std::string expected = "HELLO";
        std::string result = string_utils::to_upper(input);
        if (result != expected) {
            std::cout << "to_upper failed: expected '" << expected << "', got '" << result << "'" << std::endl;
            return 1;
        }
    }

    // Test to_lower
    {
        std::string input = "HELLO";
        std::string expected = "hello";
        std::string result = string_utils::to_lower(input);
        if (result != expected) {
            std::cout << "to_lower failed: expected '" << expected << "', got '" << result << "'" << std::endl;
            return 1;
        }
    }

    // Test replace_all
    {
        std::string input = "hello world hello";
        std::string expected = "hi world hi";
        std::string result = string_utils::replace_all(input, "hello", "hi");
        if (result != expected) {
            std::cout << "replace_all failed: expected '" << expected << "', got '" << result << "'" << std::endl;
            return 1;
        }
    }

    // Test starts_with
    {
        std::string input = "hello world";
        bool result = string_utils::starts_with(input, "hello");
        if (!result) {
            std::cout << "starts_with failed" << std::endl;
            return 1;
        }
    }

    // Test ends_with
    {
        std::string input = "hello world";
        bool result = string_utils::ends_with(input, "world");
        if (!result) {
            std::cout << "ends_with failed" << std::endl;
            return 1;
        }
    }

    // Test contains
    {
        std::string input = "hello world";
        bool result = string_utils::contains(input, "lo wo");
        if (!result) {
            std::cout << "contains failed" << std::endl;
            return 1;
        }
    }

    // Test pad_left
    {
        std::string input = "hello";
        std::string expected = "   hello";
        std::string result = string_utils::pad_left(input, 8);
        if (result != expected) {
            std::cout << "pad_left failed: expected '" << expected << "', got '" << result << "'" << std::endl;
            return 1;
        }
    }

    // Test pad_right
    {
        std::string input = "hello";
        std::string expected = "hello   ";
        std::string result = string_utils::pad_right(input, 8);
        if (result != expected) {
            std::cout << "pad_right failed: expected '" << expected << "', got '" << result << "'" << std::endl;
            return 1;
        }
    }

    // Test reverse
    {
        std::string input = "hello";
        std::string expected = "olleh";
        std::string result = string_utils::reverse(input);
        if (result != expected) {
            std::cout << "reverse failed: expected '" << expected << "', got '" << result << "'" << std::endl;
            return 1;
        }
    }

    // Test count
    {
        std::string input = "hello hello hello";
        size_t expected = 3;
        size_t result = string_utils::count(input, "hello");
        if (result != expected) {
            std::cout << "count failed: expected " << expected << ", got " << result << std::endl;
            return 1;
        }
    }

    std::cout << "All tests passed." << std::endl;
    return 0;
}