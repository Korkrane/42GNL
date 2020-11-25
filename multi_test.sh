#!/bin/bash
printf "\033[0;32mBUF=4\033[0m\n\n"
gcc -Wextra -Werror -Wall -D BUFFER_SIZE=4 get_next_line.c get_next_line_utils.c main.c
./a.out
printf "\033[0;32mBUF=32\033[0m\n\n"
gcc -Wextra -Werror -Wall -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c main.c
./a.out
printf "\033[0;32mBUF=1000000\033[0m\n\n"
gcc -Wextra -Werror -Wall -D BUFFER_SIZE=1000000 get_next_line.c get_next_line_utils.c main.c
./a.out
