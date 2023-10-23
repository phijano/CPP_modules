/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:19:15 by phijano-          #+#    #+#             */
/*   Updated: 2023/05/23 10:10:45 by phijano-         ###   ########.fr       */
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
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:

		int 				_value;
		static const int	_fractionalsBits = 8;

};

#endif
