/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:46:55 by druiz-ca          #+#    #+#             */
/*   Updated: 2023/10/01 16:41:15 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>
/* 
void printarr(int array[4][4]) // funcion comprobacion array interno
{
    int x, y = 0;
    while (x < 4) {
        y = 0;
        while (y < 4) {
            write (1, &array[x][y], 1);
            y++;
        }
        x++;
    }
    return;
}
 */
void cad_arr(int array[4][4], char *cad) // funcion pasar de cadena a array
{
    int i = 0;
    int j = 0;
    int l = 0;

    while (cad[l] !='\0') // recorremos el array
    {
        if (cad[l] >= '0' && cad[l] <= '4') // controlamos que sea nº y entre 1 y 4
        {
            if (i < 4)
            {
                array[j][i] = cad[l] - 48;
                i++;
            }
            else
            {
                if (j < 4)
                {
                    i = 0;
                    j++;
                    array[j][i] = cad[l] - 48;
                }
               
            } 
        }
        l++;
    }    
/*     printarr(array); // para comprobar que lo hace bien */
}

void rellenar_arr_int(int array[4][4], int arr_interno[4][4]) // rellena el array interno
{
    int i = 0;
    int j = 0;
    int n = 0;
    int r = 0;
    int s = 0;
    int valor;
    
    while (j < 4) 
    {
        i = 0;
        while (i < 4)
        {
            if (array[j][i] == 4) // en caso de ser 4, rellena del 1 al 4
            {
                valor  = 1;
                while (n < 4)
                {
                    arr_interno[r][s] = valor; 
                    s++;
                    valor++; 
                    n++; 
                }
            }
            if (array[j][i] == 1) // en caso de ser 1 solo rellena el 4
            {
                valor = 4;
                arr_interno[r][s] = valor;
            }
        i++;
        }
    j++;
    }
}

int main(int argc, char **argv)
{
    int array[4][4];
    int arr_interno[4][4];
    cad_arr(array, argv[1]);
    rellenar_arr_int(*array, *arr_interno);

    return (0);
}

