/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:13:44 by daniel            #+#    #+#             */
/*   Updated: 2025/02/15 13:41:32 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "phonebook.hpp"

void print(std::string str)
{
    std::string temp = str; 
    std::cout << " | ";
    if (temp.size() > 10)
    {
        temp.resize(9);
        std::cout << temp;
        std::cout << ".";
    }
    else
        std::cout << std::setw(10) << temp;
}

int main(void)
{
    std::string command;
    Phonebook PB;
    PB.num = 0;
    int i = 0;
    int selector = 0;

    while (1)
    {
        system("clear");
        std::cout << "command - ADD, SEARCH, EXIT" << std::endl;
        std::cin >> command; // cin significa console input, es decir, la entrada de la consola
        if (std::cin.eof()) // si se ha llegado al final del archivo, es decir, si en el cin no hay nada más que leer
			break ;

        if (command == "ADD")
        {
            system("clear");
            std::cout << "ADD New Contact" << std::endl;
            // si hay menos de 8 contactos se desplazan los contactos hacia abajo y el nuevo contacto se añade en la primera posición
            if (PB.num < 8)
            {
                for (int i = PB.num - 1; i >= 0; i--)
                    PB.Array_contacts[i + 1] = PB.Array_contacts[i];
            }
            else // sino se añade en la última posición y se elimina el último contacto
            {
                i = 7;
                PB.num = 7;
            }
            // sirve para limpiar el buffer de entrada (cin) y evitar errores
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "first name of contact " << std::endl;
            
            // esta linea de código sirve para leer una línea de texto de la consola y guardarla en la variable PB.Array_contacts[i].name
            std::getline(std::cin, PB.Array_contacts[i].name); 
            if (strcmp(PB.Array_contacts[i].name.c_str(), "ñ") == 0)
                std::cout << "ñ";
            if (std::cin.eof()) // por si presiona ctrl + D para salir del programa
			    break ;
            system("clear"); // sirve para limpiar la pantalla

            std::cout << "last name of ";
            std::cout << PB.Array_contacts[0].name << std::endl;
            std::getline(std::cin, PB.Array_contacts[0].lastname);
            if (std::cin.eof())
			    break ;
            system("clear");

            std::cout << "nick name of ";
            std::cout << PB.Array_contacts[i].name << std::endl;
            std::getline(std::cin, PB.Array_contacts[i].nickName);
            if (std::cin.eof())
			    break ;
            system("clear");

            std::cout << "number of ";
            std::cout << PB.Array_contacts[i].name << std::endl;
            std::getline(std::cin, PB.Array_contacts[i].phone);
            if (std::cin.eof())
			    break ;
            system("clear");

            std::cout << "darkest secret of ";
            std::cout << PB.Array_contacts[i].name << std::endl;
            std::getline(std::cin, PB.Array_contacts[i].secret);
            if (std::cin.eof())
			    break ;
            
            if (PB.num < 10) // si hay menos de 10 contactos se añade uno más
                PB.num++;
        }
        else if (command == "SEARCH" && PB.num > 0)
        {
            for (int i = 0; i < PB.num; i++)
            {
                std::cout << i + 1;
                print(PB.Array_contacts[i].name);
                print(PB.Array_contacts[i].lastname);
                print(PB.Array_contacts[i].nickName);
                std::cout << " | " << std::endl;
            }
            while (true) 
            {
                std::cout << "Type the number of the contact you want to see" << std::endl;
                std::cin >> selector;
                if (std::cin.eof())
                    break ;
                if (std::cin.fail()) // si el valor introducido no es un número
                {
                    std::cin.clear(); // sirve para limpiar el estado de error
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // limpiar el buffer de entrada (cin) y evitar errores
                    std::cout << "ERROR: INVALID INPUT. Please enter a numeric value." << std::endl;
                } 
                else if (selector > 0 && selector <= PB.num) 
                    break;
                else 
                    std::cout << "ERROR: INVALID INPUT. Please enter a number between 1 and " << PB.num << "." << std::endl;
            }
            selector--;
            system("clear");

            if (selector < PB.num && selector >= 0)
            {
                std::cout << PB.Array_contacts[selector].name << std::endl;
                std::cout << PB.Array_contacts[selector].lastname << std::endl;
                std::cout << PB.Array_contacts[selector].nickName << std::endl;
                std::cout << PB.Array_contacts[selector].phone << std::endl;
                std::cout << PB.Array_contacts[selector].secret << std::endl;
            }
            else
            {
                std::cout << "Invalid" << std::endl;
                command = "1";
            }

            while (1)
            {
                std::cout << "Type BACK - 1 to go back" << std::endl;
                std::cin >> command;
                if (command == "1" || command == "BACK")
                    break;
                if (std::cin.eof())
			        break ;
            }
        }
        else if (command == "EXIT")
            break;
        command = "X";
    }
    return (0);
}