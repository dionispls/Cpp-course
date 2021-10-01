#include <iostream>
#ifndef BALL_HPP
#define BALL_HPP

struct Point{
    double x, y;
};

struct Ball{
    Ball (Point initialPos);
    void push(double v, double alpha);
    void fly(double t);
    Point position;
    double vx, vy;
};
#endif // BALL_HPP
