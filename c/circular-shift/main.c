#include <stdint.h>
#include <limits.h>

uint32_t rotl32(uint32_t value, unsigned int count)
{
    const unsigned int mask = CHAR_BIT * sizeof(value) - 1;
    count &= mask;
    return (value << count) | (value >> (-count & mask));
}

uint32_t rotr32(uint32_t value, unsigned int count)
{
    const unsigned int mask = CHAR_BIT * sizeof(value) - 1;
    count &= mask;
    return (value >> count) | (value << (-count & mask));
}

int main(void)
{
	return 0;
}
