/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cc                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 00:33:40 by ncolomer          #+#    #+#             */
/*   Updated: 2025/05/08 12:19:08 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

int main(void)
{
	cout << "--- Constructors:" << endl;
	Warlock richard("Richard", "Master of the Universe");

	cout << "--- Introduce:" << endl;
	richard.introduce();

	cout << "--- New Title:" << endl;
	richard.setTitle("Master of the Earth");
	richard.introduce();

	cout << "--- Destructors:" << endl;
	return (0);
}
