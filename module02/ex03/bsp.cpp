/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 23:24:53 by stitovsk          #+#    #+#             */
/*   Updated: 2025/06/19 23:24:54 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed get_area(Point const a, Point const b, Point const c)
{
   Fixed area;

    area = (a.getX() * b.getY()) + (b.getX() * c.getY()) + (c.getX() * a.getY());
    area = area - (a.getX() * c.getY()) - (b.getX() * a.getY()) - (c.getX() * b.getY());
    if(area < 0)
        area = area * -1;
    return area / 2;
}

bool is_eq(Point const a, Point const b)
{
    if(a.getX() == b.getX() && a.getY() == b.getY())
        return true;
    return false;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed total_area;
    Fixed area1;
    Fixed area2;
    Fixed area3;

    if(is_eq(point, a) || is_eq(point, b) || is_eq(point, c))
        return false;
    total_area = get_area(a, b, c);
    area1 = get_area(a, b, point);
    area2 = get_area(a, c, point);
    area3 = get_area(b, c, point);
    std::cout << "Total Area: " << total_area << std::endl;
    std::cout << "Area 1 (a,b,point): " << area1 << std::endl;
    std::cout << "Area 2 (a,c,point): " << area2 << std::endl;
    std::cout << "Area 3 (b,c,point): " << area3 << std::endl;
    if(total_area == area1 + area2 + area3)
        return true;
    return false;
}