#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int ft_putstr(char *cad, int i, int cont)
{
    if (!cad)
    {
        write(1, "(null)", 6);
        return (cont + 6);
    }
    while (cad[i])
    {
        write(1, &cad[i++], 1);
        cont++;
    }
    return (cont);
}

int ft_putnum(long num, int base, int cont)
{
    char digitos[] = "0123456789abcdef";
    char cad[50];
    int i = 49;

    cad[i--] = '\0';
    if (num == 0)
    {
        write(1, "0", 1);
        return (cont + 1);
    }
    if (num < 0 && base == 10)
    {
        num *= -1;
        write(1, "-", 1);
        cont++;
    }
    if (num < 0 && base == 16)
        num = (unsigned int)num;
    while (num != 0)
    {
        cad[i--] = digitos[num % base];
        num /= base;
    }
    i++;
    cont = ft_putstr(cad, i, cont);
    return (cont);
}

int ft_printf(char *cad, ...)
{
    va_list args;
    va_start(args, cad);
    int i = 0;
    int cont = 0;

    while (cad[i])
    {
        if (cad[i] == '%' && cad[i + 1] == 's')
        {
            cont = ft_putstr(va_arg(args, char *), 0, cont);
            i++;
        }
        else if (cad[i] == '%' && cad[i + 1] == 'd')
        {
            cont = ft_putnum(va_arg(args, int), 10, cont);
            i++;
        }
        else if (cad[i] == '%' && cad[i + 1] == 'x')
        {
            cont = ft_putnum(va_arg(args, int), 16, cont);
            i++;
        }
        else
        {
            write(1, &cad[i], 1);
            cont++;
        }
        i++;
    }
    va_end(args);
    return (cont);
}

/* int main()
{
    printf("%d", ft_printf("Hello %s, %d, %x\n", "World", -42, -42));
} */



#ifndef REAL
//# define F	r += ft_printf
//#else
# define F	r += printf
#endif

 int main(void)
{
	int	r;

	r = 0;
	F("Simple test\n");
	F("");
	F("--Format---");
	F("\n");

	F("%d\n", 0);
	F("%d\n", 42);
	F("%d\n", 1);
	F("%d\n", 5454);
	F("%d\n", (int)2147483647);
	F("%d\n", (int)2147483648);
	F("%d\n", (int)-2147483648);
	F("%d\n", (int)-2147483649);
	F("\n");

	F("%x\n", 0);
	F("%x\n", 42);
	F("%x\n", 1);
	F("%x\n", 5454);
	F("%x\n", (int)2147483647);
	F("%x\n", (int)2147483648);
	F("%x\n", (int)-2147483648);
	F("%x\n", (int)-2147483649);
	F("%x\n", (int)0xFFFFFFFF);
	F("\n");

	F("%s\n", "");
	F("%s\n", "toto");
	F("%s\n", "wiurwuyrhwrywuier");
	F("%s\n", NULL);
	F("-%s-%s-%s-%s-\n", "", "toto", "wiurwuyrhwrywuier", NULL);

	F("\n--Mixed---\n");
	F("%d%x%d%x%d%x%d%x\n", 0, 0, 42, 42, 2147483647, 2147483647, (int)-2147483648, (int)-2147483648);
	F("-%d-%x-%d-%x-%d-%x-%d-%x-\n", 0, 0, 42, 42, 2147483647, 2147483647, (int)-2147483648, (int)-2147483648);
	F("\n");

	F("%s%s%s%s\n", "", "toto", "wiurwuyrhwrywuier", NULL);
	F("-%s-%s-%s-%s-\n", "", "toto", "wiurwuyrhwrywuier", NULL);

	printf("written: %d\n", r);
}