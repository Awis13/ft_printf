# ft_printf: A custom printf implementation

Hello there! Welcome to my GitHub repository for my own implementation of the `ft_printf` function, which I created as a part of my 42 École study. This custom version of the standard C `printf` function is designed to be lightweight and efficient while still providing the core functionality you'd expect from the classic `printf` function. Feel free to explore the code, ask questions, or even contribute if you'd like! 😊

## Functionality

This implementation of ft_printf supports the following format specifiers:

%d: Signed decimal integer
%s: String of characters
%c: Single character
%i: Signed decimal integer (same as %d)
%u: Unsigned decimal integer
%x: Unsigned hexadecimal integer (lowercase letters)
%X: Unsigned hexadecimal integer (uppercase letters)
%p: Pointer address
%%: A literal '%' character
How to use

To use ft_printf in your project, simply include the ft_printf.h header file and compile the ft_printf.c source file with your project.

Here's an example of how to use ft_printf in your code:

```c
#include "ft_printf.h"

int main(void)
{
    int num = 42;
    char *str = "Hello, World!";

    ft_printf("Number: %d\n", num);
    ft_printf("String: %s\n", str);
    ft_printf("Hexadecimal: %x\n", num);
    ft_printf("Pointer: %p\n", (void *)str);
}
```
License

This project is licensed under the MIT License. Feel free to use, modify, and distribute the code as you see fit.

Enjoy! 😄
