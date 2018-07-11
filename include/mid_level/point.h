//
// Created by sworddestiny on 18-7-11.
//

#ifndef ALGORITHMS_POINT_H
#define ALGORITHMS_POINT_H

#include <cmath>
using std::abs;

#define EPS 1e-10

double eps_add(double a, double b){
    if(abs(a + b) < EPS * (abs(a) + abs(b))){
        return 0;
    }
    return a+b;
}

struct Point{
    double x,y;
    Point() = default;

    Point(double xx, double yy):x(xx),y(yy){}

    Point operator+(Point p){
        return {eps_add(x,p.x),eps_add(y,p.y)};
    }

    Point operator-(Point p){
        return {eps_add(x,-p.x),eps_add(y,-p.y)};
    }

    Point operator*(double d){
        return {x*d,y*d};
    }

    double dot(Point p){
        return eps_add(x*p.x,y*p.y);
    }

    double det(Point p){
        return eps_add(x*p.y,-y*p.x);
    }

};


#endif //ALGORITHMS_POINT_H
