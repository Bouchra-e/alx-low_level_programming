#include "variadic_functions.h"
#include <stdarg.h>


/**
 * sum_them_all - calcule la somme de tous ses paramètres
 * @n: nombre de paramètres
 *
 * Return: la somme des paramètres
 */
	int sum_them_all(const unsigned int n, ...)
	{
		va_list ap;
		unsigned int i, sum = 0;


		va_start(ap, n);


		for (i = 0; i < n; i++)
			sum += va_arg(ap, int);


		va_end(ap);


		return (sum);
	}
