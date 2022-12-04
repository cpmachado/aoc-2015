#include <stdio.h>

int
evaluate(char *s, int* parity) {
	int i = 0;

	while (*s) {
		i++;
		*parity += (*s == '(') - (*s == ')');
		if (*parity == -1) {
			break;
		}
		s++;
	}

	return i;
}

int
main(void) {
	char buffer[BUFSIZ];
	int i = 0;
	int parity = 0;

	while(fgets(buffer, BUFSIZ, stdin)) {
		i += evaluate(buffer, &parity);
		if (parity == -1) {
			break;
		}
	}

	printf("%d\n", i);
	return 0;
}
