#include <stdio.h>
#include <stddef.h>

struct type_t {
	int a;
	char b;
	double c;
	char d[];
};

int main(void) {
	printf("offsets: a = %zd; b = %zd; c = %zd; d = %zd; \n",
			offsetof(struct type_t, a), offsetof(struct type_t, b),
			offsetof(struct type_t, c), offsetof(struct type_t, d));

	printf("size of type_t = %zd\n", sizeof(struct type_t));
	return 0;
}
