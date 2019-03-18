#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32_
	#include <windows.h>
#else
	#include <unistd.h>
#endif

#define block "█";
#define prefix "[\033[1;35m\t\tProgress:\033[0m [\033[1;32m"
#define suffix "\033[0m] "

static void move(double in) {
	for(int i = 0; i < in; ++i)
		printf("█");
	printf("%s\033[1;35m%.2f%%\r\033[0m", suffix, in);
	fflush(stdout);

	#ifdef _WIN32_
		Sleep(1000);
	#else
		sleep(1);
	#endif
}

void Do(double step) {
	printf("\n");
	for (int i = 0; i <= step; ++i) {
		printf("%s", prefix);
		move((i / step) * 100.);
	}
	printf("\n\n");
}
int main(int argc, char** argv) {
	if (argc < 2) {
		fprintf(stderr, "\033[1;36m Usage: ./out <steps> \n\033[0m");
		return -1;
	}
	Do(strtol(argv[1], NULL, 10));

	return 0;
}


