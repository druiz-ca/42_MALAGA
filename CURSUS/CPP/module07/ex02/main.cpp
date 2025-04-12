/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:50:49 by daniel            #+#    #+#             */
/*   Updated: 2025/04/04 17:36:37 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
    Array<int> arr(5);

    for (int i = 0; i < 5; i++)
        arr[i] = i + 1;
    
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
    cout << endl;

    try
    {
        cout << arr[5] << endl; 
    }
    catch (const std::out_of_range &e)
    {
        cout << e.what() << endl;
    }

    return 0;
    
}