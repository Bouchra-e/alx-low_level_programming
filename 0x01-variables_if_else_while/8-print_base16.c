#include <stdio.h>

/**
 * main - program that prints all single digit numbers of base 10
 *
 * Return: 0
*/

	int main(void)
	{
		char i = '0';
		char k = 'a';

		while (i <= '9')
		{
			putchar(i);
			i++;
		}
		while (k < 'g')
		{
			putchar(k);
			k++;
		}
			putchar('\n');

		return (0);
	}
