#include <stdio.h>
#include <stddef.h>

#define alignof(type) ({ \
    struct s { char c; type d; }; \
    offsetof(struct s, d); \
})

int main(int argc, char const *argv[]) {
	printf("align of int is %zd\n", alignof(int));
	return 0;
}
