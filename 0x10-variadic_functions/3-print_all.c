#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"


	/**
	 * print_all - prints anything
	 * @format: list of types of arguments passed to the function
	 */
void print_all(const char * const format, ...)
{
	va_list arg_list;
	char *str;
	unsigned int i = 0;

	va_start(arg_list, format);

	while (format && format[i])
	{
		switch (format[i])
		{
			case 'c':
				printf("%c", va_arg(arg_list, int));
				break;
			case 'i':
				printf("%d", va_arg(arg_list, int));
				break;
			case 'f':
				printf("%f", va_arg(arg_list, double));
				break;
			case 's':
				str = va_arg(arg_list, char *);
				if (str == NULL)
					str = "(nil)";
				printf("%s", str);
				break;
			default:
				i++;
				continue;
		}
		if (format[i + 1] != '\0')
			printf(", ");
		i++;
	}
	printf("\n");
	va_end(arg_list);
}
