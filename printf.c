#include <stdarg.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

/*
 * _printf.c
 *
 * This function produces output according to a format.
 *
 * Prototype: int _printf(const char *format, ...);
 * Returns: the number of characters printed (excluding the null byte used to end output to strings)
 * write output to stdout, the standard output stream
 * format is a character string. The format string is composed of zero or more directives. See man 3 printf for more detail.
 * You need to handle the following conversion specifiers:
 * c
 * s
 * %
 * You don’t have to reproduce the buffer handling of the C library printf function
 * You don’t have to handle the flag characters
 * You don’t have to handle field width
 * You don’t have to handle precision
 * You don’t have to handle the length modifiers
 */

int _printf(const char *format, ...) {
  int count = 0;
  va_list args;
  va_start(args, format);

  while (*format) {
    if (*format == '%') {
      format++;
      switch (*format) {
        case 'd': {
          int n = va_arg(args, int);
          count += printf("%d", n);
          break;
        }
        case 'i': {
          int n = va_arg(args, int);
          count += printf("%i", n);
          break;
        }
        default: {
          count += printf("%c", *format);
          break;
        }
      }
    } else {
      count += printf("%c", *format);
    }
    format++;
  }

  va_end(args);
  return count;
}
