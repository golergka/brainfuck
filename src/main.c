#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DATA_SIZE 30000

static char  data[DATA_SIZE];
static char* data_pointer;

static void reset()
{
	int i;
	for(i = 0; i < DATA_SIZE; i++)
	{
		data[i] = 0;
	}
	data_pointer = &data[0];
}

static void jump(char **input, int direction)
{
	int brackets = direction;
	while (brackets != 0)
	{
		*input += direction;
		if (**input == '[')
		{
			brackets++;
		}
		else if (**input == ']')
		{
			brackets--;
		}
	}
}

static void eval(char* input, int length)
{
	char *input_pointer = input;
	while(input_pointer < (input + length))
	{
		switch(*input_pointer)
		{
			// Increment data pointer
			case '>':
				data_pointer++;
				break;

			// Decrement data pointer
			case '<':
				data_pointer--;
				break;

			// Increment data at pointer
			case '+':
				(*data_pointer)++;
				break;

			// Decrement data at pointer
			case '-':
				(*data_pointer)--;
				break;

			// Output data at pointer
			case '.':
				printf("%c", (*data_pointer));
				break;

			// Input data at pointer
			case ',':
				if(scanf("%c", data_pointer) < 1)
				{
					*data_pointer = 0;
				}
				break;

			// Jump forward
			case '[':
				if (*data_pointer == 0)
				{
					jump(&input_pointer, 1);
				}
				break;

			// Jump backwards
			case ']':
				if (*data_pointer != 0)
				{
					jump(&input_pointer, -1);
				}
				break;

			// Ignore unknown characters
			default:
				break;
		}
		input_pointer++;
	}
}

int main(int argc, char** argv)
{
	FILE* input_file;
	char* input_program;
	long input_length;

	if (argc < 2)
	{
		printf("Please, input the filename as first parameter.");
	}
	else
	{
		reset();
		input_file = fopen(argv[1], "r");
		if (input_file)
		{
			fseek(input_file, 0, SEEK_END);
			input_length = ftell(input_file);
			fseek(input_file, 0, SEEK_SET);
			input_program = malloc(input_length);
			if (input_program)
			{
				fread(input_program, 1, input_length, input_file);
				eval(input_program, input_length);
			}
			fclose(input_file);
		}
	}
	return 0;
}
