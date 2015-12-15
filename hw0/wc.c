#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>

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

	int input;
	while ((input = fgetc(f)) != EOF)
		printf("%c\n", input);
}
