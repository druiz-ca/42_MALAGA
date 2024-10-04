/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:33:14 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/07/20 11:00:11 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// if not defined libft_h (aqui va el nombre del archivo en MAYUSCULA)
// Definela
// Abajo incluimos todas las otras librerías que vayamos a utilizar
// incluimos todas las funciones que queremos que contenga la libreria
#ifndef LIBFT_H 
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>

// Aqui van los prototipos de las funciones
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *cad);
void	*ft_memset(void *cad, int c, size_t n);
void	ft_bzero(void *cad, size_t n);
void	*ft_memcpy(void *dest, const void *cad, size_t n);
void	*ft_memmove(void *dest, const void *cad, size_t n);
size_t	ft_strlcpy(char *dest, const char *cad, size_t long_dest);
size_t	ft_strlcat(char *dest, const char *cad, size_t lendest);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *cad, int c);
char	*ft_strrchr(const char *cad, int r);
int		ft_strncmp(const char *cad1, const char *cad2, size_t n);
void	*ft_memchr(const void *cad, int c, size_t n);
int		ft_memcmp(const void *cad1, const void *cad2, size_t n);
char	*ft_strnstr(const char *cad, const char *subcad, size_t longitud);
int		ft_atoi(const char *cad);
void	*ft_calloc(size_t n, size_t medida);
char	*ft_strdup(const char *cad);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strtrim(const char	*s1, const char	*set);
char	**ft_split(const char *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list	*lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void*));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*));

#endif