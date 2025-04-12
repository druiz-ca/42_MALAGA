/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:27:15 by daniel            #+#    #+#             */
/*   Updated: 2025/04/04 17:35:27 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
void swap(T &first, T &second)
{
    T third;
    third = first;
    first = second;
    second = third;
}

template <typename T>
T min(T &first, T &second)
{
    if (first < second)
        return (first);
    return (second);
}

template <typename T>
T max(T &first, T &second)
{
    if (first > second)
        return (first);
    return (second);
}