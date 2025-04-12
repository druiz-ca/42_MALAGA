/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 13:05:22 by druiz-ca          #+#    #+#             */
/*   Updated: 2025/04/03 12:57:15 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    using namespace std;

    for (int i = 1; argv[i]; i++)
    {
        try
        {
            ScalarConverter::convert(argv[i]);
        }
        catch (const runtime_error &e)
        {
            cerr << "Error: " << e.what() << endl;
        }
        if (i < argc - 1)
            cout << endl << "----------------------------------------" << endl << endl;
    }
}