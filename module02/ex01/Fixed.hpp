/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:24:55 by phijano-          #+#    #+#             */
/*   Updated: 2023/05/23 10:19:29 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED
#define FIXED

#include <iostream>

class Fixed
{
	public:

		Fixed();
		Fixed(const Fixed &Other);
		Fixed &operator=(const Fixed &Other);
		~Fixed();
		Fixed(const int number);
		Fixed(const float number);
		int		toInt(void) const;
		float 	toFloat(void) const;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:

		int 				_value;
		static const int	_fractionalsBits = 8;

};

std::ostream &operator<<(std::ostream &os, const Fixed &fix);

#endif
