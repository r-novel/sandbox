#include <stdio.h>
#include <stdlib.h>

#define likely(x)   __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)

int main(int argc, char const *argv[]) {
	const char* home;
	home = getenv("HOME");

	if (likely(home))
		printf("home directory: %s\n", home);
	else
		perror("getenv");

	return 0;
}
