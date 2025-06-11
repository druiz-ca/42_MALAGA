#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int putstr(char *str, int i)
{
	if (!str)
		return putstr("(null)", i);
	if (!str[i]) // al hacer recursividad, cuando llega al final de la cadena, retorna la cantidad de caracteres que se imprimieron
		return i;
	return putstr(str, i + write(1, &str[i], 1));
}

int putnum(long num, int base)
{
	char *b = "0123456789abcdef";
	
	if (num < 0 && base == 10)
		return write(1, "-", 1) + putnum(num*-1, base);
	if (num < 0 && base == 16)
		return putnum((unsigned int)num, base);
	if (num/base == 0)
		return write(1, &b[num%base], 1);
	return putnum(num/base, base) + putnum(num%base, base);
}

int ptf(char *s, va_list args, int i, int n)
{
	if (!s[i])
		return n;
	if (s[i] == '%' && s[i + 1] == 's')
		return ptf(s, args, i + 2, n + putstr(va_arg(args, char *), 0));
	if (s[i] == '%' && s[i + 1] == 'd')
		return ptf(s, args, i + 2, n + putnum(va_arg(args, int), 10));
	if (s[i] == '%' && s[i + 1] == 'x')
		return ptf(s, args, i + 2, n + putnum(va_arg(args, int), 16));
	return ptf(s, args, i + 1, n + write(1, &s[i], 1));
}

int ft_printf(char *s, ...)
{
	va_list args;
	return va_start(args, s), va_end(args), ptf(s, args, 0, 0);
}
// cuando se pone en el return comas se suman los valores de las expresiones
// el valor que devuelve ft_printf es el numero de caracteres que se imprimieron
int main()
{
    printf("%i", ft_printf("Hello %s, %d, %x\n", "world", -42, -42));
    return (0);
}