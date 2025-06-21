/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:19:42 by vicana-r          #+#    #+#             */
/*   Updated: 2023/12/09 18:32:34 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
#define FT_H

typedef struct s_list
{
	int		nb;
	char	*val;
}			t_list;




int			ft_atoi(const char *str);

char		*ft_strdup(char *src);

void		ft_putstr(char *str);

char		*ft_getnb(int fd);

char		*ft_getval(int fd, char *c);

t_list		*process(char *file);

#endif
