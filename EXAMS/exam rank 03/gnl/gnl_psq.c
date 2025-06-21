# include <unistd.h>
# include <stdlib.h>	
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	while (src[i])
		i++; // como la i empieza en 0, cuando salga del bucle i va a tener la longitud de src
		// por eso en el malloc hay que añadirle 1 para el '\0'
	dest = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (src[i])
	{
	   dest[i] = src[i];
	   i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		line[70000];
	int			buffer_read;
	int 		buffer_pos;
	int			i;
	char 		*res;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (buffer_pos >= buffer_read)
		{
			buffer_read = read(fd, buffer, BUFFER_SIZE);
			if (buffer_read <= 0)
				break ;
			buffer_pos = 0;
		}
		if (line[i] == '\n')
			break ;
		line[i] = buffer[buffer_pos++];
		i++;
	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	res = ft_strdup(line);
/* 	return (res);
	res = line; */
	return (res);
}

int main()
{
    int fd = open("txt.txt", O_RDONLY);
    printf("%s", get_next_line(fd));
    return (0);
}

