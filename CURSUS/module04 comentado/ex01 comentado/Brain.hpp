/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druiz-ca <druiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:56:32 by daniel            #+#    #+#             */
/*   Updated: 2025/03/01 12:29:15 by druiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

using std::string;

class Brain
{
    public:
        Brain();
        Brain(Brain const &copy);
        ~Brain();
        Brain const &operator=(Brain const &copy);
        string const getIdea(int const &index) const;
        void setIdea(string const &idea, int const index);
    private:
        string _ideas[100];
};

/*
array of 100 std::string called ideas.
Dog and Cat will have a private Brain* attribute.
Upon construction, Dog and Cat will create their Brain using new Brain();
Upon destruction, Dog and Cat will delete their Brain
In your main function, create and fill an array of Animal objects.
Half of it will be Dog objects and the other half will be Cat objects.
At the end of your program execution, loop over this array and delete every Anima
You must delete directly dogs and cats as Animals
The appropriate destructors must be called in the expected order.
Don’t forget to check for memory leaks.
A copy of a Dog or a Cat mustn’t be shallow. 
Thus, you have to test that your copies
are deep copies!
*/