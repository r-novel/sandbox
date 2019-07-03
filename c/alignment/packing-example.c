#include <stdio.h>
#include <stdint.h>

struct example_t {
	uint64_t a;
	uint32_t b;
	uint8_t  c;
};

#pragma pack(push, 1)
struct packed_example_t {
	uint64_t a;
	uint32_t b;
	uint8_t  c;
};
#pragma pack(pop)

struct sec_packed_example_t {
	uint64_t a;
	uint32_t b;
	uint8_t  c;
}__attribute__(( packed, aligned(1) ));

void dump() {
	printf("full size of raw struct: %zd\n", sizeof(struct example_t));
	printf("full size of struct with pragma pack: %zd\n", sizeof(struct packed_example_t));
	printf("full size of struct with attr packed: %zd\n", sizeof(struct sec_packed_example_t));

}

int main(int argc, char** argv) {
	dump();

	return 0;
}
