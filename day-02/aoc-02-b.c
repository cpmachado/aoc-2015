#include <stdio.h>

#define MIN(A, B) (A < B ? A : B)


int
evaluate(char *s) {
	int l, w, h;
	int minperimeter;
	int lw, wh, hl;

	if (sscanf(s, "%dx%dx%d", &l, &w, &h) != 3) {
		return 0;
	}

	lw = l + w;
	wh = w + h;
	hl = h + l;

	minperimeter = 2 * MIN(lw, (MIN(wh, hl)));
	
	return  l * w * h + minperimeter;
}

int
main(void) {
	char buffer[BUFSIZ];
	int sum = 0;

	while(fgets(buffer, BUFSIZ, stdin)) {
		sum += evaluate(buffer);
	}

	printf("%d\n", sum);

	return 0;
}
