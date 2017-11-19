# STR Manip

This is a collection of simple C++17 string manipulation utilities.

- Avoid any and all memory allocations unless necessary.
- Minimize API surface.

## split()

Lazilly split a string across a delimiter.

```#include "str_manip/split.h"```

Usage:
```
std::string_view src = "aa:bb:cc";
std::string_view delim = ":";

for(auto s : slt::split(src, delim)) {
  std::cout << s << std::endl;
}
```

Notes:
- Splitting the empty string returns an empty range
- If source starts or ends with a delimiter, the range will contain empty strings
