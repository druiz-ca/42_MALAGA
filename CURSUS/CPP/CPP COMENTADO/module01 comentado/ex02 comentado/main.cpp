/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:11:57 by daniel            #+#    #+#             */
/*   Updated: 2025/01/21 19:33:55 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;
    

    std::cout << "The memory address of the string variable: " << &str << std::endl;
    // 0x16ef0f1c8
    std::cout << "The memory address of the string variable: " << &str[0] << std::endl;
    // HI THIS IS BRAIN -> imprime todo el string porque en c++ si el << recibe la pos
    // 0 de un string imprime todo el string
    std::cout << "The memory address of the string variable: " << &str[6] << std::endl;
    // S IS BRAIN
    std::cout << "The memory address of the string variable: " << str[6] << std::endl;
    // S

    
    std::cout << "The memory address held by stringPTR: " << stringPTR << std::endl;
    // 0x16ef0f1c8
    std::cout << "The memory address held by stringREF: " << &stringREF << std::endl;
    // 0x16ef0f1c8 (imprime también la dir de mem aunque lleve &)
    
    std::cout << std::endl;
    std::cout << "The value of the string variable: " << str << std::endl;
    std::cout << "The value pointed to by stringPTR: " << stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;
}
/*
<< &str[0]
esto imprime toda la cadena de caracteres
si se pone solo &str, imprime la dirección de memoria del primer caracter
&str[6] imprime la dirección de memoria del 7º caracter
*/