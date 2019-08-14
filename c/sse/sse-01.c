#include <stdio.h>

float a[4] = { 300.0, 4.0, 4.0, 12.0 };
float b[4] = {   1.5, 2.5, 3.5,  4.5 };

/*
a:
	[xxxxxxxx][xxxxxxxx][xxxxxxxx][xxxxxxxx]
	[xxxxxxxx][xxxxxxxx][xxxxxxxx][xxxxxxxx]
	[xxxxxxxx][xxxxxxxx][xxxxxxxx][xxxxxxxx]
	[xxxxxxxx][xxxxxxxx][xxxxxxxx][xxxxxxxx]
	// 128 bit

b:
	[xxxxxxxx][xxxxxxxx][xxxxxxxx][xxxxxxxx]
	[xxxxxxxx][xxxxxxxx][xxxxxxxx][xxxxxxxx]
	[xxxxxxxx][xxxxxxxx][xxxxxxxx][xxxxxxxx]
	[xxxxxxxx][xxxxxxxx][xxxxxxxx][xxxxxxxx]
	// 128 bit

size of xmm0 register is 128 bit;

1) mov A packet data to xmm0;
2) mov B packet data to xmm1;
3) multi arrays value by value;
4) mov result to A array;

*/


int main(void) {
	printf("A: %f %f %f %f\n", a[0], a[1], a[2], a[3]);
	printf("B: %f %f %f %f\n", b[0], b[1], b[2], b[3]);

 __asm__ volatile (
  "movups %[a], %%xmm0\n\t"
  "movups %[b], %%xmm1\n\t"
  "mulps %%xmm1, %%xmm0\n\t"
  "movups %%xmm0, %[a]\n\t"
  :
  : [a]"m"(*a), [b]"m"(*b)
  : "%xmm0", "%xmm1"
 );

 printf("\nR: %f %f %f %f\n", a[0], a[1], a[2], a[3]);

	return 0;
}

