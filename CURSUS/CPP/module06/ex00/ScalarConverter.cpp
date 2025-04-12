/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 13:52:43 by druiz-ca          #+#    #+#             */
/*   Updated: 2025/04/03 12:59:39 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
using namespace std;

ScalarConverter::ScalarConverter()
{
    cout << "Default constructor is called" << endl;
}

ScalarConverter::ScalarConverter(const string &str)
{
    cout << "Copy constructor is called" << endl;
    *this = str;
}

ScalarConverter::~ScalarConverter()
{
    cout << "Destructor is called" << endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &str)
{
    return *this;
}

void printChar(string input)
{
    cout << "char: '" << input << "'" << endl;
    cout << "int: " << static_cast<int>(input[0]) << endl;
    cout << "float: " << static_cast<float>(input[0]) << "f" << endl;
    cout << "double: " << static_cast<double>(input[0]) << endl;
}

bool isDigit(string input)
{
    int i = 0;
    if (input[0] == '-')
        i++;
    for(; i < input.length(); i++)
    {
        if (isdigit(input[i]))
            return false;
    }
    if (input.find('.') != string::npos)
        return false;
    return true;
}

void printInt(string input)
{
    int i = strtol(input.c_str(), NULL, 10);

    long double value;
    istringstream iss(input); 
    iss >> value;
 
    if (value < 32 || value > 126) 
        cout << "char: Non displayable" << endl;
    else
        cout << "char: '" << static_cast<char>(i) << "'" << endl;

    if (value > numeric_limits<int>::max() || value < numeric_limits<int>::min())
        cout << "int: impossible" << endl;
    else
        cout << "int: " << i << endl;

    if (value > numeric_limits<int>::max())
        cout << "float: inff" << endl;
    else if (value < -numeric_limits<int>::max())
        cout << "float: -inff" << endl;
    else
        cout << "float: " << static_cast<float>(i) << ".0f" << endl;

    if (value > numeric_limits<int>::max())
        cout << "double: inf" << endl; 
    else if (value < -numeric_limits<int>::max()) 
        cout << "double: -inf" << endl; 
    else
        cout << "double: " << i << ".0" << endl;
    
}

bool isFloat(string input)
{
    int i = 0;
    if (input[i] == '-' || input[i] == '+')
        i++;
    if (count(input.begin(), input.end(), '.') != 1)
        return false;
    for (; i <= (int)input.length(); i++)
    {
        if (isdigit(input[i]) && (input[i] != '.'))
            return false;
    }
    if (input[input.length() - 1] != 'f' && input[input.length() - 1] != 'F')
        return false;
    return true;
}

void printFloat(string input)
{
    float f = strtof(input.c_str(), NULL);

    long double value;
    istringstream iss(input);
    iss >> value;

    if (value < 32 || value > 126)
        cout << "char: Non displayable" << endl;
    else
        cout << "char: '" << static_cast<char>(f) << "'" << endl;

    if (value > numeric_limits<int>::max() || value < numeric_limits<int>::min())
        cout << "int: impossible" << endl;
    else
        cout << "int: " << static_cast<int>(f) << endl;

    if (value > numeric_limits<float>::max())
        cout << "float: inff" << endl;
    else if (value < -numeric_limits<float>::max())
        cout << "float: -inff" << endl;
    else
        cout << "float: " << f << "f" << endl;

    if (value > numeric_limits<double>::max())
        cout << "double: inf" << endl; 
    else if (value < -numeric_limits<double>::max()) 
        cout << "double: -inf" << endl; 
    else
        cout << "double: " << static_cast<double>(f) << endl;
}

bool isDouble(string input)
{
    int i = 0;
    if (input[i] == '-' || input[i] == '+')
        i++;
    if (count(input.begin(), input.end(), '.') != 1)
        return false;
    for (; i <= (int)input.length(); i++)
    {
        if (isdigit(input[i]) && (input[i] != '.'))
            return false;
    }
    return true;
}

void printDouble(string input)
{
    double d = strtod(input.c_str(), NULL);

    long double value;
    istringstream iss(input);
    iss >> value;

    if (value < 32 || value > 126)
        cout << "char: Non displayable" << endl;
    else
        cout << "char: '" << static_cast<char>(d) << "'" << endl;

    if (value > numeric_limits<int>::max() || value < numeric_limits<int>::min())
        cout << "int: impossible" << endl;
    else
        cout << "int: " << static_cast<int>(d) << endl;

    if (value > numeric_limits<float>::max())
        cout << "float: inff" << endl;
    else if (value < -numeric_limits<float>::max())
        cout << "float: -inff" << endl;
    else
        cout << "float: " << static_cast<float>(d) << "f" << endl;

    if (value > numeric_limits<double>::max())
        cout << "double: inf" << endl; 
    else if (value < -numeric_limits<double>::max()) 
        cout << "double: -inf" << endl; 
    else
        cout << "double: " << d << endl;
}

string errorft(string input)
{
    string error;
    if (input == "inf" || input == "+inf")
        error = "inf";
    else if (input == "-inf")
        error = "-inf";
    else
        error = "nan";
    return error;
}

void ScalarConverter::convert(const string &input)
{
    if (input.length() == 1 && isdigit(input[0]))
        return (printChar(input));
    else if (isDigit(input))
        return (printInt(input));
    else if (isFloat(input))
        return (printFloat(input));
    else if (isDouble(input))
        return (printDouble(input));
    else
    {
        string error = errorft(input);
        cout << "char: impossible" << endl;
        cout << "int: impossible" << endl;
        cout << "float: " << error << "f" << endl;
        cout << "double: " << error << endl;
    }
}