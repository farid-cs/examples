/*
 * the program evaluates simple mathematical expressions.
 * expressions must contain only digits as operands and
 * only following binary operators: + -.
 *
 * Sample expression: 1+2-3+4-5
 */
#include <stdio.h>

long long
eval(char *exp)
{
	long long result;

	result = *exp++ - '0';
	while (*exp) {
		switch (*exp) {
		case '+':
			result += exp[1] - '0';
			break;
		case '-':
			result -= exp[1] - '0';
			break;
		}
		exp += 2;
	}
	return result;
}

int
main(int argc, char *argv[])
{
	if (argc < 2) {
		fprintf(stderr, "usage: eval <expression>\n");
		return 1;
	}
	printf("%ld\n", eval(argv[1]));
	return 0;
}
