#include "main.h"
/**
 * _puts_recursion - print a string recursively
 * @s: the string to print
 *
 * return:void
 */
void _puts_recursion(char *s)
{
if (*s == '\0')
{
_putchar('\n');
return;
}
_putchar(*s);
_puts_recursions(s + 1);
}
