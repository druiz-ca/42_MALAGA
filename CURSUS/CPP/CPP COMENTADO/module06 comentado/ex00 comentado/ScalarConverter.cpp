/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 13:52:43 by druiz-ca          #+#    #+#             */
/*   Updated: 2025/04/01 20:25:02 by daniel           ###   ########.fr       */
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
    // para convertir un string a un int en base 10
    int i = strtol(input.c_str(), NULL, 10);

    // otra forma de convertir un string a un long double
    long double value;
    istringstream iss(input); // creamos un objeto de tipo istringstream
    iss >> value; // guarda el contenido de iss en value

    // char
    if (value < 32 || value > 126) // si no es un caracter imprimible
        cout << "char: Non displayable" << endl;
    else // lo que hace es convertir el int a un char
        cout << "char: '" << static_cast<char>(i) << "'" << endl;

    // int
        // numeric_limits<int>::max() devuelve el valor maximo que puede tener un int
    if (value > numeric_limits<int>::max() || value < numeric_limits<int>::min())
        cout << "int: impossible" << endl;
    else
        cout << "int: " << i << endl;

    // float
    if (value > numeric_limits<int>::max())
        cout << "float: inff" << endl; // indica que el valor es demasiado grande para ser representado
    else if (value < -numeric_limits<int>::max()) // la - indica que es el valor negativo
        cout << "float: -inff" << endl; // indica que el valor es demasiado pequeño para ser representado
    else
        cout << "float: " << static_cast<float>(i) << ".0f" << endl;

    // double
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
    // COMPROBAR SI HAY MAS DE UN PUNTO
        // count devuelve el numero de veces que aparece un caracter en un string
        //.begin() devuelve un iterador al primer elemento del string
        //.end() devuelve un iterador al ultimo elemento del string
    if (count(input.begin(), input.end(), '.') != 1)
        return false;
    //CASTEAR (int) porque el length devuelve un size_t
    for (; i <= (int)input.length(); i++)
    {// si es un digito y no es un punto a la vez????
        if (isdigit(input[i]) && (input[i] != '.'))
            return false;
    }
    // si al final del string no hay una f o F
    if (input[input.length() - 1] != 'f' && input[input.length() - 1] != 'F')
        return false;
    return true;
}

void printFloat(string input)
{
    // para convertir un string a un float en base 10
    float f = strtof(input.c_str(), NULL);

    // otra forma de convertir un string a un long double
    long double value;
    istringstream iss(input); // creamos un objeto de tipo istringstream
    iss >> value; // guarda el contenido de iss en value

    // char
    if (value < 32 || value > 126) // si no es un caracter imprimible
        cout << "char: Non displayable" << endl;
    else // lo que hace es convertir el float a un char
        cout << "char: '" << static_cast<char>(f) << "'" << endl;

    // int
    if (value > numeric_limits<int>::max() || value < numeric_limits<int>::min())
        cout << "int: impossible" << endl;
    else
        cout << "int: " << static_cast<int>(f) << endl;

    // float
    if (value > numeric_limits<float>::max())
        cout << "float: inff" << endl; // indica que el valor es demasiado grande para ser representado
        // inff es un valor que se usa para representar un valor demasiado grande
    else if (value < -numeric_limits<float>::max()) // la - indica que es el valor negativo
        cout << "float: -inff" << endl; // indica que el valor es demasiado pequeño para ser representado
    else
        cout << "float: " << f << "f" << endl;

    // double
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
    // desde el comienzo (input.begin()) hasta el final (input.end()) del string
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
    // para convertir un string a un double en base 10
    double d = strtod(input.c_str(), NULL);

    // otra forma de convertir un string a un long double
    long double value;
    istringstream iss(input); // creamos un objeto de tipo istringstream
    iss >> value; // guarda el contenido de iss en value

    // char
    if (value < 32 || value > 126) // si no es un caracter imprimible
        cout << "char: Non displayable" << endl;
    else // lo que hace es convertir el double a un char
        cout << "char: '" << static_cast<char>(d) << "'" << endl;

    // int
    if (value > numeric_limits<int>::max() || value < numeric_limits<int>::min())
        cout << "int: impossible" << endl;
    else
        cout << "int: " << static_cast<int>(d) << endl;

    // float
    if (value > numeric_limits<float>::max())
        cout << "float: inff" << endl; // indica que el valor es demasiado grande para ser representado
    else if (value < -numeric_limits<float>::max()) // la - indica que es el valor negativo
        cout << "float: -inff" << endl; // indica que el valor es demasiado pequeño para ser representado
    else
        cout << "float: " << static_cast<float>(d) << "f" << endl;

    // double
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