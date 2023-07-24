#include "shell.h"

/**
 * long_to_string - a function that converts a number to a string.
 * @number: number to be converten in an string.
 * @string: buffer to save the number as string.
 * @base: base to convert number
 * Return: always 0
 */

void long_to_string(long number, char *string, int base)
{
	int index = 0, inNegative = 0;
	long cociente = number;
	char letters[] = {"0123456789abcdef"};

	if (cociente == 0)
		string[index++] = '0';

	if (string[0] == '-')
		inNegative = 1;

	while (cociente)
	{
		if (cociente < 0)
			string[index++] = letters[-(cociente % base)];
		else
			string[index++] = letters[cociente % base];
		cociente /= base;
	}
	if (inNegative)
		string[index++] = '-';

	string[index] = '\0';
	str_reverse(string);
}

/**
 * _atoi - a function that convert a string to an integer.
 * @s: pointer to str origen.
 * Return: int of string or 0.
 */

int _atoi(char *s)
{
	int sign = 1;
	unsigned int number = 0;

	while (!('0' <= *s && *s <= '9') && *s != '\0')
	{
		if (*s == '-')
			sign *= -1;
		if (*s == '+')
			sign *= +1;
		s++;
	}

	while ('0' <= *s && *s <= '9' && *s != '\0')
	{

		number = (number * 10) + (*s - '0');
		s++;
	}
	return (number * sign);
}

/**
 * count_characters - a function that count the coincidences
 * of character in string.
 * @string: pointer to str origen.
 * @character: string with  chars to be counted
 * Return: int of string or 0.
 */

int count_characters(char *string, char *character)
{
	int m = 0, counter = 0;

	for (; string[m]; m++)
	{
		if (string[m] == character[0])
			counter++;
	}
	return (counter);
}
