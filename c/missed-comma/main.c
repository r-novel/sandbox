#include <stdio.h>

int main(int argc, char const *argv[])
{
	if (argc > 1) printf("more than...\n"), argv[1] = (int)strtol(argv[1], NULL, 10), ++argv[1], printf("increase a: %d\n", argv[1]);
}
