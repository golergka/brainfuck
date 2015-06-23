#include <stdio.h>
#include <string.h>

#define MEMORY_SIZE 30000

static char memory[MEMORY_SIZE];

static void eval(char* input)
{
	int i;
	char* instruction_pointer;
	for(i = 0; i < strlen(input); i++)
	{
		instruction_pointer = &input[i];
		printf("%c", *instruction_pointer);
	}
}

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		printf("Detected no input");
	}
	else
	{
		eval(argv[1]);
	}
	return 0;
}
