# StringUtils

A lightweight, header-only C++ library providing common string manipulation utilities. Compatible with C++11+.

## Installation
- Copy the `include/string_utils.hpp` file into your project's include path.
- In your CMakeLists.txt, add `include_directories(path/to/StringUtils/include)`.

No compilation required for the library itself.

## Usage
Include the header:
```cpp
#include "string_utils.hpp"
```

## Function Reference

| Function | Description | Example Input | Example Output |
|----------|-------------|---------------|----------------|
| `trim_left(s)` | Remove leading whitespace | `"  hello"` | `"hello"` |
| `trim_right(s)` | Remove trailing whitespace | `"hello  "` | `"hello"` |
| `trim(s)` | Remove leading and trailing whitespace | `"  hello  "` | `"hello"` |
| `split(s, delimiter)` | Split string by delimiter | `split("a,b,c", ',')` | `{"a", "b", "c"}` |
| `join(vector, delimiter)` | Join vector of strings | `join({"a", "b"}, ",")` | `"a,b"` |
| `to_upper(s)` | Convert to uppercase | `"hello"` | `"HELLO"` |
| `to_lower(s)` | Convert to lowercase | `"HELLO"` | `"hello"` |
| `replace_all(s, from, to)` | Replace all occurrences | `replace_all("foo bar foo", "foo", "baz")` | `"baz bar baz"` |
| `starts_with(s, prefix)` | Check if string starts with prefix | `starts_with("hello", "hel")` | `true` |
| `ends_with(s, suffix)` | Check if string ends with suffix | `ends_with("hello", "lo")` | `true` |
| `contains(s, substr)` | Check if string contains substring | `contains("hello", "ell")` | `true` |
| `pad_left(s, width, char)` | Pad string on the left | `pad_left("5", 3, '0')` | `"005"` |
| `pad_right(s, width, char)` | Pad string on the right | `pad_right("5", 3, '0')` | `"500"` |
| `reverse(s)` | Reverse the string | `"hello"` | `"olleh"` |
| `count(s, substr)` | Count occurrences of substring | `count("hello", "l")` | `2