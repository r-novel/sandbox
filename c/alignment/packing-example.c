#include <stdio.h>
#include <stdint.h>

struct ex1_t {
	uint64_t a;
	uint32_t b;
	uint16_t c;
	uint8_t d;
};

struct ex2_t {
	uint8_t a;
	uint16_t b;
	uint32_t c;
	uint64_t d;
};

struct ex3_t {
	uint64_t a;
	uint8_t b;
	uint32_t c;
};

struct ex4_t {
	uint64_t a;
	uint64_t b;
	uint32_t c;
};

struct ex5_t {
	uint64_t a;
	uint64_t b;
	uint32_t c;
	uint8_t d;
};

int main(int argc, char const *argv[]) {
	printf("\nfirst example struct:\n"
		"\tstruct { \n"
			"\tuint64_t a - %zd bytes;\n"
			"\tuint32_t b - %zd bytes;\n"
			"\tuint16_t c - %zd bytes;\n"
			"\tuint8_t  d - %zd bytes;\n"
		"\t}\n", sizeof(uint64_t), sizeof(uint32_t),
					sizeof(uint16_t), sizeof(uint8_t));

	printf("full size of struct: %zd\n", sizeof(struct ex1_t));

	printf("\nsecond example struct:\n"
		"\tstruct { \n"
			"\tuint8_t  a - %zd bytes;\n"
			"\tuint16_t b - %zd bytes;\n"
			"\tuint32_t c - %zd bytes;\n"
			"\tuint64_t d - %zd bytes;\n"
		"\t}\n", sizeof(uint8_t), sizeof(uint16_t),
					sizeof(uint32_t), sizeof(uint64_t));

	printf("full size of struct: %zd\n", sizeof(struct ex2_t));

	printf("\nthird example struct:\n"
		"\tstruct { \n"
			"\tuint64_t  a - %zd bytes;\n"
			"\tuint8_t b - %zd bytes;\n"
			"\tuint16_t c - %zd bytes;\n"
		"\t}\n", sizeof(uint64_t), sizeof(uint8_t),
					sizeof(uint16_t));

	printf("full size of struct: %zd\n", sizeof(struct ex3_t));

	printf("\nfourth example struct:\n"
		"\tstruct { \n"
			"\tuint64_t  a - %zd bytes;\n"
			"\tuint64_t b - %zd bytes;\n"
			"\tuint32_t c - %zd bytes;\n"
		"\t}\n", sizeof(uint64_t), sizeof(uint64_t),
					sizeof(uint32_t));

	printf("full size of struct: %zd\n", sizeof(struct ex4_t));

	printf("\nfifth example struct:\n"
		"\tstruct { \n"
			"\tuint64_t  a - %zd bytes;\n"
			"\tuint64_t b - %zd bytes;\n"
			"\tuint32_t c - %zd bytes;\n"
			"\tuint8_t d - %zd bytes;\n"
		"\t}\n", sizeof(uint64_t), sizeof(uint64_t),
					sizeof(uint32_t), sizeof(uint8_t));

	printf("full size of struct: %zd\n", sizeof(struct ex5_t));

	return 0;
}
