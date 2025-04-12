/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 13:52:53 by druiz-ca          #+#    #+#             */
/*   Updated: 2025/04/03 12:59:45 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>

using namespace std;

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const string &src);
        ~ScalarConverter();
        ScalarConverter &operator=(const ScalarConverter &src);

    public:
        static void convert(const string &str);
            
};