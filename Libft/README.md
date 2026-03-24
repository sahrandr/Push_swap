*This project has been created as part of the 42 curriculum by sahrandr.*

# Description

**Libft** is a foundational project of the 42 curriculum.  
Its goal is to build a personal C library by reimplementing a set of standard libc functions, as well as additional utility functions and basic linked list handling.

This project helps students:
- Understand how common C standard functions work internally
- Improve memory management skills
- Write clean, reusable, and well-structured C code
- Build a library that will be reused throughout future projects

The result is a static library (`libft.a`) containing general-purpose functions for string manipulation, memory handling, character checks, I/O helpers, and linked lists.

---
## Instructions

### Compilation

To compile the library, simply run:

```bash
make
```
This will generate the `libft.a` static library at the root of the repository.

## Makefile rules

The Makefile includes the following rules:

- `make` or `make all` – compile the library

- `make clean` – remove object files

- `make fclean` – remove object files and `libft.a`

- `make re` – recompile everything from scratch

- `make bonus` – compile bonus (linked list) functions

## Usage

To use **libft** in another project:

**1.Copy the `libft` folder into your project**

**2.Compile it using its Makefile**

**3.Include the header:**
```c
#include "libft.h"
```
Link the library during compilation:
```bash
-Llibft -lft
```
## Library Content
### Part 1 – Libc Functions

Reimplementation of standard libc functions, all prefixed with ft_, including:

Character checks:
`ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`

String & memory functions:
`ft_strlen`, `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`
`ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`,
`ft_strncmp`, `ft_strnstr`

Case conversion:
`ft_toupper`, `ft_tolower`

Memory comparison & search:
`ft_memchr`, `ft_memcmp`

Conversion & allocation:
`ft_atoi`, `ft_calloc`, `ft_strdup`

### Part 2 – Additional Functions

Utility functions not present (or not identical) in libc:

String manipulation:
`ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`

Conversion:
`ft_itoa`

Functional string iteration:
`ft_strmapi`, `ft_striteri`

File descriptor output:
`ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`

### Part 3 – Linked List Functions (Bonus)

Implementation of a simple singly linked list using the following structure:
```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
} t_list;
```

### Available functions:

`ft_lstnew`

`ft_lstadd_front`

`ft_lstsize`

`ft_lstlast`

`ft_lstadd_back`

`ft_lstdelone`

`ft_lstclear`

`ft_lstiter`

`ft_lstmap`

### Technical Constraints

Written in C

Fully compliant with the 42 Norm

Compiled `with -Wall -Wextra -Werror`

No global variables

No memory leaks

Only allowed external functions are used

Library built using `ar` (no `libtool`)

### Resources

- man pages (`man strlen`, `man memcpy`, etc.)

- youtube

- google

- GeeksforGeegs

### AI Usage

AI tools were used only for clarification and documentation purposes, such as:

- Understanding function behavior from man pages

- Structuring the README file

All implementations were written manually in accordance with the 42 learning guidelines.

### Author

sahrandr – 42 Student
