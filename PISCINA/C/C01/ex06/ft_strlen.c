/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:14:50 by druiz-ca          #+#    #+#             */
/*   Updated: 2023/09/25 16:23:55 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strlen(char *str)
{
    int i;
    int num;
    num = 0;
    i = 0;
    
    while (str[i] !='\0')
    {
        i++;
        num++;
    }
    return(num);
}

int main(void)
{
    char *str;
    str = "Hossssla";
    
    ft_strlen(str);
    return 0;
}