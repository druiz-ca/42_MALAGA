/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:16:44 by daniel            #+#    #+#             */
/*   Updated: 2025/04/04 17:35:35 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

template <typename T>
void print(const T &x)
{
    cout << x;
}

template <typename T>
void addOne(T &x)
{
    x++;
}

template <typename T, typename N>
void iter(T *array, int length, N function)
{
    for (int i = 0; i < length; i++)
        function(array[i]);
}