/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 11:09:58 by druiz-ca          #+#    #+#             */
/*   Updated: 2025/04/06 14:10:24 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

/* STACK
    - 

*/

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    cout << mstack.top() << std::endl;
    mstack.pop();
    cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);

    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        cout << *it << endl;
        ++it;
    }
    stack<int> s(mstack);
    return 0;
}