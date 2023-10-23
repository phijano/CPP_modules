/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:01:37 by phijano-          #+#    #+#             */
/*   Updated: 2023/08/03 09:55:32 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE
 #define BASE

#include <iostream>

class Base
{
	public:

		virtual ~Base();
};

class A: public Base
{
};

class B: public Base
{
};

class C: public Base
{
};

#endif
