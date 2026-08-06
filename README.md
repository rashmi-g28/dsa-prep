# DSA-prep

Compact collection of C++ data-structures & algorithms practice problems (solutions and helpers).

**Prerequisites**
- **Compiler**: Install `g++` (MinGW on Windows or system `g++` / `clang++` on macOS/Linux).
- **Optional**: A code editor such as VS Code.

**Compile & Run**
- **Create bin folder**: `mkdir bin`
- **Compile a single file**: `g++ -std=c++17 -O2 -Wall -Wextra -o bin/<name>.exe <path/to/file.cpp>`
- **Run (Windows)**: `.\bin\<name>.exe`  — **Run (Unix)**: `./bin/<name>`

Example (Windows PowerShell):
```
mkdir bin
g++ -std=c++17 -O2 -Wall -Wextra -o bin/two-sum.exe arrays/two-sum.cpp
.\bin\two-sum.exe
```

**Project Structure**
- **Root files**: [anagaram.cpp](anagaram.cpp), [group-anagrams.cpp](group-anagrams.cpp), [reverse-string.cpp](reverse-string.cpp), [unique-character.cpp](unique-character.cpp), [valid-palindrome-II.cpp](valid-palindrome-II.cpp)
- **arrays/**: classic array problems (examples: [arrays/two-sum.cpp](arrays/two-sum.cpp), [arrays/rotate-array.cpp](arrays/rotate-array.cpp))
- **dynamic-programming/**: DP problems (examples: [dynamic-programming/climbing-stairs.cpp](dynamic-programming/climbing-stairs.cpp), [dynamic-programming/knapsack-0-1.cpp](dynamic-programming/knapsack-0-1.cpp))
- **strings/**: string-focused problems (contains-duplicate related files)
- **warmup/**: easy warm-up problems (examples: [warmup/plusOne.cpp](warmup/plusOne.cpp), [warmup/palindrome-number.cpp](warmup/palindrome-number.cpp))

**Contributing**
- **Add solutions**: Add or improve solutions; keep filenames descriptive.
- **Style**: Prefer C++17, simple IO, and short self-contained files.

**Notes**
- This repository is meant for practicing interview-style problems. Adapt compile flags as needed for your environment.
