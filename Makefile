CFLAGS = -std=c99 -Wall -Wextra -Werror
main: proj1.c
	gcc proj1.c -o proj1
clean:
	rm proj1