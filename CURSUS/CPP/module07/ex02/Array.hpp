/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:51:02 by daniel            #+#    #+#             */
/*   Updated: 2025/04/04 17:36:18 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

template <typename T>
class Array
{
    public:
        Array() : _array(NULL), _size(0) {}
        
        Array(unsigned int size) : _array(NULL), _size(size)
        {
            if (this->_size == 0)
                throw std::out_of_range("Index out of range");
            this->_array = new T[_size]();
        }

        Array(const Array &copy) : _array(NULL), _size(0)
        {
            *this = copy;
        }
        
        ~Array()
        {
            if (this->_array != NULL)
                delete[] _array;
        }
        
        Array &operator=(const Array &copy)
        { 
            if (this->_array != NULL)
                delete[] this->_array;
            if (copy._size != 0)
            {
                this->_array = new T[copy._size]();
                for (unsigned int i = 0; i < this->getSize(); i++)
                    this->_array[i] = copy._array[i];
                this->_size = copy._size;
            }
            return *this;
        }
        T &operator[](size_t index)
        {  
            if (index >= this->_size)
                throw std::out_of_range("Index out of range");
            return this->_array[index];
        }
        
        size_t getSize() const
        {
            return this->_size;
        }

    private:
        T *_array;
        size_t _size;
};