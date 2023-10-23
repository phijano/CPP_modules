/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:46:49 by phijano-          #+#    #+#             */
/*   Updated: 2023/05/23 10:57:30 by phijano-         ###   ########.fr       */
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

		bool operator>(const Fixed &Other) const;
		bool operator<(const Fixed &Other) const;
		bool operator>=(const Fixed &Other) const;
		bool operator<=(const Fixed &Other) const;
		bool operator==(const Fixed &Other) const;
		bool operator!=(const Fixed &Other) const;

		Fixed operator+(const Fixed &Other) const;
		Fixed operator-(const Fixed &Other) const;
		Fixed operator*(const Fixed &Other) const;
		Fixed operator/(const Fixed &Other) const;

		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);

		static const Fixed &max(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &min(Fixed &a, Fixed &b);

	private:

		int 				_value;
		static const int	_fractionalsBits = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fix);


#endif
