#include <iostream>
#ifndef BALL_HPP
#define BALL_HPP

struct Point{
    double x, y;
};

struct Molecule{
    Molecule (Point initialPos);
    void push(double v, double alpha);
    void fly(double t);
    Point position;
    double vx, vy;
    bool interact(Molecule another);
};
#endif // BALL_HPP
