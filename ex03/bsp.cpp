/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hparveen <hparveen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:25:32 by hparveen          #+#    #+#             */
/*   Updated: 2025/11/18 08:38:01 by hparveen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Point.hpp"

static Fixed cross(const Point &p, const Point &a, const Point &b)
{
    return(p.getX() - b.getX()) * (a.getY() - b.getY()) - (p.getY() - b.getY()) * (a.getX() - b.getX());
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed d1 = cross(point, a, b);
    Fixed d2 = cross(point, b, c);
    Fixed d3 = cross(point, c, a);

    bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    if(has_neg && has_pos)
        return false;

    if(d1 == 0 || d2 == 0 || d3 == 0)
        return false;

    return true;
}
