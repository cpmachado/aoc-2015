#include <stdio.h>

int
evaluate(char *s) {
	int parity = 0;

	while (*s) {
		if (*s == '(') {
			parity += 1;
		} else if (*s == ')') {
			parity -= 1;
		}
		s++;
	}

	return parity;
}

int
main(void) {
	char buffer[BUFSIZ];
	int acc = 0;

	while(fgets(buffer, BUFSIZ, stdin)) {
		acc += evaluate(buffer);
	}

	printf("%d\n", acc);
	return 0;
}
