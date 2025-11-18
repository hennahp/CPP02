/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hparveen <hparveen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:25:46 by hparveen          #+#    #+#             */
/*   Updated: 2025/11/18 09:24:36 by hparveen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

# define CYAN "\033[36m"
# define GREEN "\033[32m"
# define RESET "\033[0m"

class Point
{
    private:
        Fixed const   _x;
        Fixed const   _y;

    public:
        Point();
        Point(const float x, const float y);
        Point(const Point &other);
        Point &operator=(const Point &other);
        ~Point();

        Fixed getX() const;
        Fixed getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif