#include <stdio.h>

int
evaluate(char *s) {
	int parity = 0;

	while (*s) {
		parity += (*s == '(') - (*s == ')');
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
