/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:04:07 by daniel            #+#    #+#             */
/*   Updated: 2025/02/15 13:54:53 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void myreplace(std::string filename, std::string s1, std::string s2)
{
    std::fstream    in_file; 
    std::fstream    out_file;
    std::string     line;
    std::string     aux;
    size_t  pos; 
    
    pos = 0;

    in_file.open(filename.c_str(), std::ios::in); 
    out_file.open((filename + ".replace").c_str(), std::ios::out);
    while(std::getline(in_file, line))
    {
        size_t i = 0;
        while (i < line.length())
        {
            pos = line.find(s1, i);
            if (pos != std::string::npos)
            {
                out_file << line.substr(i, pos - i) << s2;
                i = pos + s1.length();
            }
            else
            {
                out_file << line.substr(i, line.length() - i) << std::endl;
                break;
            }
        }
    }
    std::cout << "File has been created!" << std::endl;
    
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