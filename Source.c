#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

enum MyEnumType
{
	BLUE = 1,
	GREEN = 2,
	RED = 3
};

enum BoolType
{
	ETHAN_TRUE = 1,
	ETHAN_FALSE = 0
};

void Sqrtthingy(short *i)
{
	
	*i = (short) sqrt((double) *i);


}

int Sqrtthingy2(double* i)
{
	return sqrt(*i);
}

void SqrtThingy3(double in, double* pout)
{
	*pout = sqrt(in);
}

int main()
{
	enum MyEnumType met;
	met = BLUE;

	enum BoolType b;
	b = ETHAN_TRUE;

	if (met == RED)
	{
		// print "blah";
	}
	if (met == BLUE)
	{
		printf("met is blue\n");
	}

	int arrayof20[20] = { 0 };
	int twodimar[10][10] = { 0 };

	

	short input = 16; // indirect value (what the memory points TO)
	short * pInput = &input; // direct value (the memory pointer in memory)
	Sqrtthingy(pInput);
	printf("%d", (int) input);

	// floating point # not very accurate. double is better, but still lossy
	// so if you try to do a loop with a specific value it's looking for, it will probably break or not work right
	for (float f = 0; f != 10.0f; f += 1.0f)
	{
		// this won't work. adding 1.0 to f each time will NOT get you exactly to 10.0f, though it seemns logical.
		// BECAUSE in this case, we're testing for an exact match. if you tested for >= 10, then it may or may not
		// stop right before the 10 or right after the 10. If it adds 0.999 each time to f, instead of 1.0, then it
		// may print out one extra #.

		printf("%f\n", f);
	}

	FILE* pFile = fopen("d:\\testfile.txt", "r");
	while (false)
	{
		char c;
		int read = fscanf(pFile, "%c", &c);
		if (read <= 0)
		{
			break;
		}
		printf("%c", c);
		Sleep(100);
	}

	unsigned char uc = 255; // 0-255
	signed char sc = 127; // -128 to 127
	unsigned short us = 65535; // 0 - 65535
	signed short ss = 32767; // -32768 to 32767 (remember the range is 65536, so half the range = 32768)
	//                       v- 2nd power of 16 = 256, so F * 256 = 3840
	//                        v- 1st power of 16 = 16, so F * 16 = 240
	//                         v- 0th power of 16 = 1, so F * 1 = 15
	//                           0xFFF = 3840 + 240 + 15 = 4095!
	unsigned int ui = 0xFFFFFFFF; 
	signed int si = 0x8FFFFFFF; // 32 bits

	unsigned long ul = ui; // also 32 bits
	signed long sl = si; // also 32 bits

	unsigned long long ull = 0xFFFFFFFFFFFFFFFF; // 64 bits
	signed long long sll = 0x8FFFFFFFFFFFFFFF;
	
	// char = 8 bit
	// short = 16 bit
	// int = 32 bit
	// long = 32 bit
	// long long = 64 bit

	int i = 65538;
	printf("i = 0x%x\n", i);
	short s = i;
	char cc = i;
	float f = round(1.55f);
	int intf = f;

	// the first bit, called "most significant bit" = 1, for a signed number, signifies "this number is negative"
	//                  v- most significant bit
	// short 0x8000 = 0b1000000000000000, the most signficant bit is a 1, means "this is a signed number"
	// (this works for any integer type)
	// for a signed short, the most positive number you can have is
	// 0b 0111 1111 1111 1111 = 0x7FFF. That's the most positive signed short you can get!
	// 0b 0110 1111 1111 1111 = 0x6FFF. 
	// 0b 0XXX XXXX = positive
	// 0b 1XXX xxxx = negative. If MSB of 1 is in the left column, the hex # is going to start with a # that is 8 or higher
	// because leading '1' in MSB = 8


	short sle = -32768;
	sle--;

	printf("uc = %u, sc = %d, us = %u, ss = %d, ui = %u, si = %d, ul = %llu, sl = %lld\n", uc, sc, us, ss, ui, si, ull, sll);

	return 0;
}