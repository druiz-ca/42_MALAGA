/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:51:02 by daniel            #+#    #+#             */
/*   Updated: 2025/04/04 17:33:52 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

// plantilla de una clase! 

template <typename T>
class Array
{
    public:
        Array() : _array(NULL), _size(0) {}
        
        Array(unsigned int size) : _array(NULL), _size(size)
        {
            if (this->_size == 0)
                throw std::out_of_range("Index out of range");
            // asigna memoria a un array de elemntos de tipo T
            this->_array = new T[_size]();
        }

        Array(const Array &copy) : _array(NULL), _size(0)
        {
            *this = copy;
        }
        
        ~Array()
        {
            if (this->_array != NULL)
            // como es un array el delete se hace con delete[]
                delete[] _array;
        }
        
        Array &operator=(const Array &copy)
        {   // si tuviera memoria asignada antes la libera
            if (this->_array != NULL)
                delete[] this->_array;
            // si la variable size contiene algo que no sea 0 la copia
            if (copy._size != 0)
            {
                // asigna memoria al array de la variable this
                this->_array = new T[copy._size]();
                // copia el contenido del array de la variable copy
                for (unsigned int i = 0; i < this->getSize(); i++)
                    this->_array[i] = copy._array[i];
                // asigna el tamaño del array de la variable copy
                this->_size = copy._size;
            }
            return *this;
        }
        // SOBRECARGA DEL OPERADOR DE INDEXADO
        // para poder acceder al elemento "index" del array
        T &operator[](size_t index)
        {   // si la posición que solicita está fuera de rango:
            if (index >= this->_size)
                throw std::out_of_range("Index out of range");
            return this->_array[index];
            // develve la referencia a la posición del array index
        }
        
        // const para que no se pueda modificar el array
        size_t getSize() const
        {
            return this->_size;
        }

    private:
        // puntero a un array que contiene elementos de tipo T
        T *_array;
        size_t _size;
};