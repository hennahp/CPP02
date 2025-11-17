/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hparveen <hparveen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:25:43 by hparveen          #+#    #+#             */
/*   Updated: 2025/11/17 13:02:04 by hparveen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point(const float x,const float y): _x(x), _y(y)
{
}
Point::Point(const Point &other) : _x(other._x), _y(other._y)
{
}

Point &Point::operator=(const Point &other)
{
    (void)other;
    return *this;
}

Point::~Point()
{
}

Fixed Point::getX() const
{
    return this->_x;
}

Fixed Point::getY() const
{
    return this->_y;
}
