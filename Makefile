all:
	clang -c main.c -o main.o -Wall -Wextra -Werror -g
	clang -c lib/lib.c -o lib.o -Wall -Wextra -Werror -g 
	clang main.o lib.o -o bin -Wall -Wextra -Werror -g 
