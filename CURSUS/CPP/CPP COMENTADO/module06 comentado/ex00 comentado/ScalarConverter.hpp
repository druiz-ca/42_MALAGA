/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 13:52:53 by druiz-ca          #+#    #+#             */
/*   Updated: 2025/04/06 10:57:33 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <limits> // numeric_limits
#include <algorithm> // count

// tengo que incluir antes la liberia para que el using funcione!!
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