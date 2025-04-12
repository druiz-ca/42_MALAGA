/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:57:28 by daniel            #+#    #+#             */
/*   Updated: 2025/04/03 13:01:42 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"


Base *generate(void)
{  
    srand((unsigned)time(NULL));
    switch (int num = rand() % 3) 
    {
        case 0: 
            return (new A());
        case 1: 
            return (new B());
        case 2: 
            return (new C());
        default: return (NULL);
    }
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        cout << "The object is of type A" << endl;
    else if (dynamic_cast<B*>(p))
        cout << "The object is of type B" << endl;
    else if (dynamic_cast<C*>(p))
        cout << "The object is of type C" << endl;
    else
        cout << "Unknown type" << endl;
}

void identify(Base &p)
{ 
    try
    {
        (void) dynamic_cast<A&>(p);
        cout << "The object is of type A" << endl;
    }
    catch (exception &e)
    {
        try
        {
            (void) dynamic_cast<B&>(p);
            cout << "The object is of type B" << endl;
        }
        catch (exception &e)
        {
            try
            {
                (void) dynamic_cast<C&>(p);
                cout << "The object is of type C" << endl;
            }
            catch (exception &e)
            {
                cout << "Unknown type" << endl;
            }
        }
    }
}

int main()
{
    Base *p;
    for (int i = 0; i < 4; i++)
    {
        p = generate();
        identify(p);
        identify(*p);
        delete p;
        cout << endl;
        sleep(1);
    }
    Base *c = NULL;
    if (c != NULL) {
        identify(*c);
    } else {
        cout << "Pointer is NULL, cannot identify." << endl;
    }
}