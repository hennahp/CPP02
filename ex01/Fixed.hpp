/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hparveen <hparveen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 10:37:48 by hparveen          #+#    #+#             */
/*   Updated: 2025/11/07 10:54:52 by hparveen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define ORANGE "\033[38;5;208m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

class Fixed
{
    private:
        int                 _rawBits;
        static const int    _fractionalBits = 8;

    public:
        Fixed();
        Fixed(const int n);
        Fixed(const float f);
        Fixed(const Fixed &other);
        Fixed &operator=(const Fixed &other);
        ~Fixed();
        
        int getRawBits(void) const;
        void setRawBits(int const raw);

        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif