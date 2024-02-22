<h1 align="center">
	<p>
	ft_printf
	</p>
	<img src="https://github.com/aaron-22766/aaron-22766/blob/main/42-badges/ft_printfm.png">
</h1>

<p align="center">
	<b><i>Because putnbr and putstr aren’t enough</i></b><br><br>
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/aaron-22766/42_ft_printf?color=lightblue" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/aaron-22766/42_ft_printf?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/aaron-22766/42_ft_printf?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/aaron-22766/42_ft_printf?color=green" />
</p>

---

## 🗣 About

The goal of this project is pretty straightforward. You will recode printf. You will mainly learn about using a variable number of arguments. How cool is that?? It is actually pretty cool :) You will learn what is and how to implement variadic functions. Once you validate it, you will reuse this function in your future projects.

## 🛠 Usage

### Requirements

The library is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.

### Instructions

**1. Compiling the library**

To compile the library, run:

```shell
$ cd path/to/printf && make
```

**2. Using it in your code**

To use the library functions in your code, simply include its header:

```C
#include "ft_printf.h"
```

**3. Link your program with libft.a**

```Makefile
PRINTF_DIR = path/to/printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

$(NAME): $(PRINTF)
	gcc $(PRINTF) $(MY_SRCS)...

$(PRINTF):
	make -C $(PRINTF_DIR)
```

## 💬 Description

Works just like printf of the `stdio` header. Because I had so much fun with this project I took the time to implement even more functions from the printf family, like dprintf, vdprintf, asprintf and vasprintf. These I added to my [massively expanded libft](https://github.com/aaron-22766/libft) which I used in all my projects later on.

### Mandatory

Implemented conversion characters are:
- `%c` Prints a single character.
- `%s` Prints a string (as defined by the common C convention).
- `%p` The void * pointer argument has to be printed in hexadecimal format.
- `%d` Prints a decimal (base 10) number.
- `%i` Prints an integer in base 10.
- `%u` Prints an unsigned decimal (base 10) number.
- `%x` Prints a number in hexadecimal (base 16) lowercase format.
- `%X` Prints a number in hexadecimal (base 16) uppercase format.
- `%%` Prints a percent sign.

### Bonus

Implemented flags:
- `-` Left-justify within the given field width; Right justification is the default (see width sub-specifier).
- `0` Left-pads the number with zeroes (0) instead of spaces when padding is specified (see width sub-specifier).
- `#` Used with x or X specifiers the value is preceeded with 0, 0x or 0X respectively for values different than zero.
- `(space)` If no sign is going to be written, a blank space is inserted before the value.
- `+` Forces to preceed the result with a plus or minus sign (+ or -) even for positive numbers. By default, only negative numbers are preceded with a - sign.
- `.` For integer specifiers (d, i, u, x, X): precision specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. A precision of 0 means that no character is written for the value 0.

Width sub-specifier:

`(number)` Minimum number of characters to be printed. If the value to be printed is shorter than this number, the result is padded with blank spaces. The value is not truncated even if the result is larger.
