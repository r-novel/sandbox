#include "extract.h"

int main(int argc, char** argv) {
	if (argc < 2) {
		fprintf(stdout, "Usage: ./extract <archive_file>\n");
	}

	int res = extract(argv[1]);
	if (res < 0) {
		fprintf(stderr, "error extract archive;\n");
		return -1;
	}

	return 0;
}