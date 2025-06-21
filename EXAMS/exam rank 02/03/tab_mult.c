#include <unistd.h>
#include <stdio.h>

int ft_atoi(char *cad)
{
    int num = 0;
    int i = 0;
    while (cad[i])
    {
        num = num * 10 + (cad[i] - '0');
        i++;
    }
    return (num);
}
char *ft_itoa(int num, int longitud)
{
    char res[longitud];
    char *res_ptr;
    res[longitud--] = '\0';
    while (num > 0)
    {
        res[longitud--] = num % 10 + '0';
        num /= 10;
    }
    res_ptr = res;
    return (res_ptr);
}
char *calcular(char mult, int num)
{
    char *res;
    int longitud = 0;
    int num2 = 0;
    int res_num = 0;
    
    res_num = (mult - '0') * num;
    num2 = res_num;
    while (num2 > 0)
    {
        num2 /= 10;
        longitud++;
    }
    res = ft_itoa(res_num, longitud);
    return(res);
}
int ft_strlen(char *cad)
{
    int i = 0;
    while (cad[i])
        i++;
        return (i);
}
int main(int ac, char **av)
{
    int num = 0;
    char mult = '1';
    char *cad = av[1];
    if (ac == 2)
    {
        while (mult <= '9')
        {
            write(1, &mult, 1);
            write(1, " * ", 3);
            write(1, cad, ft_strlen(cad));
            write(1, " = ", 3);
            write(1, calcular(mult, ft_atoi(cad)), 3);
            write(1, "\n", 1);
            mult++;
        }
    }
    else
        write(1, "\n", 1);
    //printf("%s", av[1]);
}