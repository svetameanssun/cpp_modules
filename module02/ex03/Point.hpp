#ifndef POINT_HPP
 # define POINT_HPP

# include <iostream>
# include "Fixed.hpp"

class Point
{
    private:
        Fixed const _x;
        Fixed const _y;
    public:
        Point();
        Point(const Point &point);
        Point(Fixed const x, Fixed const y);
        ~Point();

        Fixed getX() const;
        Fixed getY() const;
        
        Point & operator = (const Point &point);
};
 
std::ostream & operator << (std::ostream &out, const Point &point);

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif