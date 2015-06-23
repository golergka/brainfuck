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

static void eval(char* input)
{
	while(*input != EOF)
	{
		switch(*input)
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
				scanf(" %c", data_pointer);
				break;

			// Jump forward
			case '[':
				if (*data_pointer == 0)
				{
					while(*input != ']')
					{
						input++;
					}
				}
				break;

			// Jump backwards
			case ']':
				if (*data_pointer != 0)
				{
					while(*input != '[')
					{
						input--;
					}
				}
				break;

			// Ignore unknown characters
			default:
				break;
		}
		input++;
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
		reset();
		eval(argv[1]);
	}
	return 0;
}
