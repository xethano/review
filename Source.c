#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

struct BattleGrid
{
	bool Guessed;
	bool Hit;
	char Comment[256];
	int BoatIndex;
};

struct BattleGrid2
{
	bool Guessed;
	bool Hit;
	char Comment[256];
};

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

int AddNumbers(int array[], int lengthofarray)
{
	int tempval = 0;
	for (int i = 0; i < lengthofarray; i++)
	{
		tempval += array[i];
	}
	return tempval;
}

int AddNumbersPtr(int * array, int lengthofarray)
{
	int tempval = 0;
	for (int i = 0; i < lengthofarray; i++)
	{
		tempval += *array; // take the indirect (pointed to) value in the array
		array++; // <- this is a special ++ operator and tells the int * to

		// the below line is exactly equivalent. But don't increment array++
		// tempval += array[i];
	}
	return tempval;
}

int StringLength(char array[])
{
	int index = 0;
	while (array[index] != '\0')
	{
		index++;
	}
	return index;
}

void StringCopyFake( char destination[], const char source[])
{
	int index = 0;
	
	while (source[index] != '\0')
	{
		destination[index] = source[index];
		index++;
	}
	destination[index] = '\0';
}

void AppendString(char destination[], const char addition[])
{
	int dest_leng = StringLength(destination);
	StringCopyFake(destination+dest_leng, addition);
}

int StringCompare(const char array[], const char array2[])
{
	
	int index = 0;
	
	while (true)
	{
		if (array[index] == '\0' && array2[index] != '\0')
		{
			return 1;
		}
		if (array[index] != '\0' && array2[index] == '\0')
		{
			return -1;
		}
		if (array[index] == array2[index] && array2[index] == '\0')
		{
			return 0;
		}

		char tempc = array[index];
		char tempd = array2[index];
		if (tempc > tempd)
		{
			return -1;
		}
		if (tempc < tempd)
		{
			return 1;
		}
		index++;
	}
}




void PointerArith(int* pArray, int len)
{
	while (len > 0)
	{
		*pArray = 10;
		pArray++;
		pArray++;
		len--;
		len--;
	}
}




int main()
{

	int TestArray[] = { 4, 6, 1, 2, 9, 22 };
	PointerArith(TestArray, 6);
	for (int iii = 0; iii < 6; iii++)
	{
		printf("%d ", TestArray[iii]);
	}

	struct BattleGrid grid[10] = { 0 };

	// the below, grid[2] IS a grid struct, not a pointer to one. so you use '.'
	grid[2].BoatIndex = 2;
	grid[2].Guessed = true;

	// this is a POINTER to a grid struct, so you use "->"
	struct BattleGrid* pGridPtr = &grid[3];
	pGridPtr->BoatIndex = 4;
	pGridPtr->Hit = true;

	// this wipes out BoatIndex = 4, and replaces ALL of the fields of grid[3] with
	// those of grid[2]!!!
	grid[3] = grid[2];

	struct BattleGrid2 bg2[3];
	// grid[3] = bg2[1]; nope

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
	int twodimar[10][5] = { 0 };
	
	// assign values to each element in the array
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			twodimar[x][y] = y * 10 + x;
		}
	}

	// print row (not column) 2 of the array
	for (int x = 0; x < 10; x++)
	{
		printf("%d ", twodimar[x][1]);
		
	}
	printf("\n");

	for (int y = 0; y < 5; y++)
	{
		printf("%d ", twodimar[2][y]);

	}

















	int array5[] = { 0,1,2,3,4 };
	const char* arraychar[] = { "et", "bru" };

	// stringroutines
	const char* szString = "Test String"; // null terminator is secretly appended to the string
	int szLen = strlen(szString); // does not include null terminator.
	char szCopy[256]; // has to be bigger than or equal in size to what we're copying
	strcpy(szCopy, szString);
	strcat(szCopy, "blahblah");
	int result = strcmp(szCopy, "Test Stringclahblah");
	if (result == 1)
	{
		printf("they're equal\n");
	}

	int sum0 = AddNumbers(array5, 5);
	int sum1 = AddNumbersPtr(array5, 5);
	int testi = 20;
	int sumTesti = AddNumbersPtr(&testi, 1); // will return 20


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