/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 11:10:21 by druiz-ca          #+#    #+#             */
/*   Updated: 2025/04/06 14:19:04 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list> // para usar list
#include <stack> // para usar stack

using namespace std;


// DEFINO LA PLANTILLA DE LA CLASE MUTANTSTACK
template <typename T>
// hereda de la clase stack(le pasa el tipo de dato que va a usar)
//    - stack es un contenedor adaptador que proporciona la funcionalidad de una pila (LIFO: Last In First Out)
class MutantStack: public stack<T> 
{
    public:
        // DEFINO EL TIPO DE ITERADOR QUE VOY A USAR:
            // TYPEDEF crea un alias para un tipo de dato: iterator
            // TYPENAME sirve para indicar que el tipo de dato es un tipo definido dentro de la clase
            // STACK<T> es un contenedor adaptado que utiliza otro contenedor como base (subyacente)
            // CONTAINER_TYPE es el tipo de contenedor subyacente utilizado por la pila
            // ITERATOR: es el ripo de iterador definido por el contenedor subyacente
        typedef typename stack<T>::container_type::iterator iterator;
        MutantStack();
        MutantStack(const MutantStack &src);
        ~MutantStack();
        MutantStack &operator=(const MutantStack &src);
        
        // metodo que devuelve un iterador al principio de la pila
        iterator begin();
        // metodo que devuelve un iterador al final de la pila
        iterator end();
    
};

//COMO EL SUBJECT NO ESPECIFICA QUE SE USE UN .CPP PARA IMPLEMENTACIONES LO HAGO AQUI

template <typename T>
MutantStack<T>::MutantStack()
{
    cout << "Default constructor is called" << endl;
}; // al estar en el archivo .hpp tengo que cerrar los corchetes con ;!!

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &src)
{
    cout
    *this = src;
};

template <typename T>
MutantStack<T>::~MutantStack()
{
    cout << "Destructor of MutantStack is called" << endl;
};

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &src)
{
    cout << "mutant Stack copy asignment operator is called" << endl;
    stack<int>::operator=(src);
    return *this;
};

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{   // la c es de la clase stack y es el contenedor subyacente
    return this->c.end();
};

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return this->c.end();
};

/*
Un **contenedor** en C++ es una estructura de datos que forma parte de la biblioteca estándar (STL, Standard Template Library) y que se utiliza para almacenar y organizar colecciones de elementos. Los contenedores proporcionan una interfaz uniforme para trabajar con datos, permitiendo operaciones como agregar, eliminar, acceder y recorrer elementos.

### Tipos de contenedores en la STL:
La STL ofrece varios tipos de contenedores, cada uno diseñado para diferentes necesidades:

1. **Secuenciales**:
   - Almacenan elementos en un orden específico.
   - Ejemplos:
     - `std::vector`: Un arreglo dinámico que permite acceso rápido por índice.
     - `std::deque`: Una doble cola que permite inserciones y eliminaciones rápidas en ambos extremos.
     - `std::list`: Una lista enlazada doble que permite inserciones y eliminaciones rápidas en cualquier posición.

2. **Asociativos**:
   - Almacenan elementos en estructuras que permiten búsquedas rápidas.
   - Ejemplos:
     - `std::set`: Almacena elementos únicos en orden.
     - `std::map`: Almacena pares clave-valor en orden.
     - `std::unordered_set` y `std::unordered_map`: Versiones no ordenadas basadas en tablas hash.

3. **Adaptadores de contenedores**:
   - No son contenedores en sí mismos, sino que adaptan otros contenedores para proporcionar una funcionalidad específica.
   - Ejemplos:
     - `std::stack`: Implementa una pila (LIFO) utilizando un contenedor subyacente (por defecto, `std::deque`).
     - `std::queue`: Implementa una cola (FIFO) utilizando un contenedor subyacente.
     - `std::priority_queue`: Implementa una cola de prioridad.
*/