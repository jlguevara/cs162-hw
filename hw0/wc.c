#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
	FILE *f;

	if (argc == 2) {
		char *filename = argv[1];

		f = fopen(filename, "r");
		if (f == NULL) {
			printf("errno: %d\n", errno);
			perror(filename);
			exit(1);
		}
	}
	else if (argc == 1) {
		f = stdin;
	}
	else {
		printf("Wrong number of arguments\n");
		return 1;
	}

	int input;
	int	lines = 0, words = 0;
	bool inword = false;

	while ((input = fgetc(f)) != EOF) {
		if (isspace(input))
			inword = false;
		else if (!inword) {
			inword = true;
			words++;
		}

		if (input == '\n')
			lines++;

	}
	
	printf("%8d%8d\n", lines, words);
}
