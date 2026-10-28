*This project has been created as part of the 42 curriculum by yokour.*

# ft_printf

## Description

`ft_printf` is a 42 Common Core project that recreates a subset of the standard C `printf` function. It writes formatted output to standard output and returns the number of characters printed, or a negative value if an output error occurs.

The project focuses on variadic functions, format-string parsing, number conversion, and low-level output using `write`.

### Supported conversions

| Conversion | Description |
| --- | --- |
| `%c` | Print one character |
| `%s` | Print a string |
| `%p` | Print a pointer address in hexadecimal |
| `%d` / `%i` | Print a signed decimal integer |
| `%u` | Print an unsigned decimal integer |
| `%x` | Print hexadecimal using lowercase letters |
| `%X` | Print hexadecimal using uppercase letters |
| `%%` | Print a literal percent sign |

The project builds a static library named `libftprintf.a`. It implements the mandatory conversion set without reproducing the buffering behavior of the original `printf`.

## Instructions

### Build

Run these commands in the project directory:

```sh
make         # Build libftprintf.a
make all     # Build libftprintf.a
make clean   # Remove object files
make fclean  # Remove object files and libftprintf.a
make re      # Rebuild from scratch
```

The Makefile compiles the project with `-Wall -Wextra -Werror` and archives the object files using `ar`.

### Usage

Include the project's header in your C source file:

```c
#include "printf.h"

int main(void)
{
    ft_printf("Hello, %s!\n", "42");
    ft_printf("Number: %d, hex: %x\n", 42, 42);
    return (0);
}
```

Compile and link your test program with the library:

```sh
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o test_printf
./test_printf
```

The header is currently named `printf.h` in this project. If it is renamed, update both the source includes and the Makefile dependency accordingly.

## Algorithm and Data Structures

The main `ft_printf` function scans the format string from left to right. Regular characters are written directly to standard output. When it encounters `%`, it reads the next conversion specifier and retrieves the appropriate argument with `va_arg` when needed.

Helper functions handle characters, strings, signed numbers, and unsigned/base conversion. The number-conversion logic uses arithmetic operations such as division and remainder; the base-conversion implementation stores digits in a local character array and prints them in reverse extraction order. A running counter tracks successful output, and the return values of output operations are used to detect errors.

The implementation uses an index, counters, `va_list`, pointers, and local character arrays. It does not require a complex data structure.

## Resources

- [W3Schools — C Tutorial](https://www.w3schools.com/c/) — Used to review C syntax, functions, loops, pointers, and strings.
- [GeeksforGeeks — C Programming Language](https://www.geeksforgeeks.org/c-programming-language/) — Used to study variadic functions, recursion, memory concepts, and number conversion.

### AI Usage

ChatGPT was used as a learning assistant to answer questions, explain programming concepts, and provide guidance while I worked on the project.

## Author

- **42 login:** `yokour`
- **GitHub:** [youok04](https://github.com/youok04)
