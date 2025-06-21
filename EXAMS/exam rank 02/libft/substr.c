/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 12:04:01 by druiz-ca          #+#    #+#             */
/*   Updated: 2024/03/17 13:01:06 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char *ft_substr(char *cad, int desde, int longitud)
{
    int i = 0;
    char *sub_cad;
    int j = 0;

    sub_cad = malloc(sizeof(char) * longitud);
    while (j <= longitud)
    {
        sub_cad[j++] = cad[desde++];
    }
    sub_cad[j] = '\0';
    return (sub_cad);
}

int main()
{
    write(1, ft_substr("hola pepe", 4, 4), 4);
    //printf("%s", ft_substr("hola pepe", 4, 4));
}