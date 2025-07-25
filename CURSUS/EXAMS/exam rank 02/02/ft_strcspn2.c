
size_t ft_strcspn(char *cad1, char *cad2)
{
    size_t i = 0;

    while (cad1[i])
    {
        j = 0;
        while (cad2[j])
        {    
            if (cad1[i] == cad2[j])
                return (i)      
            j++;
        }
        i++;
    }
    return (0);
}

int main()
{
    printf("%d", ft_strcspn("pepe", "pepe"));
}