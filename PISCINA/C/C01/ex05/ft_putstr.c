/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:08:04 by druiz-ca          #+#    #+#             */
/*   Updated: 2023/10/09 16:27:16 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putstr(char *str)
{
    int i;
    i=0;

    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
}
int main (void)
{
    char *str;
    str = "Hola";
    ft_putstr(str);
    return 0;
}