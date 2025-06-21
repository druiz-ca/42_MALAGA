/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:04:07 by daniel            #+#    #+#             */
/*   Updated: 2025/01/26 13:52:05 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream> // para trabajar con archivos

void myreplace(std::string filename, std::string s1, std::string s2)
{
    std::fstream    in_file; // podria ser ifstream
    std::fstream    out_file; // podria ser ofstream
    std::string     line;
    std::string     aux;
    //char c;
    size_t  pos; //pq luego hay que comparar con npos
    
    pos = 0;
    //size_t          find_value;

    // open: abre un archivo
    // c.str() convierte el string en un puntero a char
    // std::ios::in abre el archivo en modo lectura (in)
    in_file.open(filename.c_str(), std::ios::in); 
    
    // abre el archivo en modo escritura (out)
    // concateno ".replace" al nombre del archivo, sino se crearia
    // un archivo con el mismo nombre que el original y se sobre escribiria
    out_file.open((filename + ".replace").c_str(), std::ios::out);

    /* // in:file.eof -> mientras no llegue al final del archivo
    // noswkipws -> mientras que pueda leer un caracter
    while(!in_file.eof() && in_file >> std::noskipws >> c)
        aux += c;
    in_file.close(); // cierra el archivo

    for (size_t i = 0; i < aux.length(); i++)
    {
        // busca la primera ocurrencia de s1 en aux a partir de la posicion i
        pos = aux.find(s1, i);
        // si pos es distinto de npos es que encontro la cadena
        //(npos es el valor devuelto por find cuando no encuentra la cadena)
        if (pos != std::string::npos && pos == i)
        {
            out_file << s2;
            i += s1.length() - 1;
        }
        else
            out_file << aux[i];
    } */
    
    while(std::getline(in_file, line))// mientras que pueda leer una linea
    {
        size_t i = 0; // size_t pq al comparar con lo que devuelve length()
        while (i < line.length()) // mientras q no termine de recorrer la linea
        {
            pos = line.find(s1, i); //busca s1 desde la pos i en la linea, devuelve la pos
            // si pos es distinto de npos es que encontro la cadena
            if (pos != std::string::npos)
            {
                // con los << se escribe en el archivo
                // << es un operador de inserción: inserta el contenido de la variable
                out_file << line.substr(i, pos - i) << s2;
                i = pos + s1.length();
            }
            else
            {
                out_file << line.substr(i, line.length() - i) << std::endl;
                break;
            }
        }
        // cuando ha recorrido toda la linea sale y carga la nueva linea
    }
    std::cout << "File has been created!" << std::endl;
    
    // cierra los archivos
    in_file.close();
    out_file.close();
    return ;
}

int main(int argc, char **argv)
{
    if (argc == 4)
    {
        if (!argv[2][0])
            std::cout << "Error: empty string is not allowed." << std::endl;
        else
            myreplace(argv[1], argv[2], argv[3]);
    }
    else
        std::cout << "Error: number of arguments is not correct." << std::endl;
    return (0);
}   

/*
std::ifstream: para entrada desde archivo (lectura)
std::ofstream: para salida a archivo (escritura)
std::fstream: para ambas!!
*/