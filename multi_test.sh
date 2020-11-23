#!/bin/bash
printf "\033[0;31mBUF=4\033[0m\n"
gcc -Wextra -Werror -Wall -D BUFFER_SIZE=4 pseudo.c get_next_line_utils3.c
./a.out
printf "\033[0;31mBUF=32\033[0m\n"
gcc -Wextra -Werror -Wall -D BUFFER_SIZE=32 pseudo.c get_next_line_utils3.c
./a.out
printf "\033[0;31mBUF=1000000\033[0m\n"
gcc -Wextra -Werror -Wall -D BUFFER_SIZE=1000000 pseudo.c get_next_line_utils3.c
./a.out
