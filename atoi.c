#include "shell.h"

/**
 * interactive - true if shell is interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 if it fails
 */

int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - function that checks if character is a delimeter
 * @c:  char to check
 * @delim:  delimeter string
 * Return: 1 if true, returns 0 if it false
 */

int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 *_isalpha - function that checks for alphabetic character
 *@c: The character to input
 *Return: 1 if c is alphabetic, 0 if it fails
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - function that converts a string to an integer
 *@s: the string to be converted
 *Return: converted number, otherwise 0
 */

int _atoi(char *s)
{
	int i, x = 1, y = 0, output;
	unsigned int result = 0;

	for (i = 0;  s[i] != '\0' && y != 2; i++)
	{
		if (s[i] == '-')
			x *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			y = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (y == 1)
			y = 2;
	}

	if (x == -1)
		output = -result;
	else
		output = result;

	return (output);
}
