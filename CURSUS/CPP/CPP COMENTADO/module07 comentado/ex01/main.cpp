/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:16:30 by daniel            #+#    #+#             */
/*   Updated: 2025/04/04 12:48:38 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
    int array[] = {1, 2, 3, 4, 5};
    
    cout << "Before function" << endl;
    iter(array, 5, print<int>);
    cout << endl;
    iter(array, 5, addOne<int>);
    cout << endl;
    cout << "After function" << endl;
    iter(array, 5, print<int>);
    cout << endl;
}