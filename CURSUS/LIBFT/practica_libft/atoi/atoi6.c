#include <stdio.h>

int main()
{
    char *cad = " -12345";
    int n = 0;
	int i = 0;
	int op = 1;

	while (cad[i] == ' ')
		i++;
	while (cad[i] == '-')
	{
		i++;
		op *= -1;
	}
	while (cad[i] >= '0' && cad[i] <= '9')
	{
		n = n * 10 + (cad[i] - '0');
		i++;
	}
	if (op == -1)
		n *= op;
	printf("%i", n);
}