#include <iostream>
#ifndef BALL_HPP
#define BALL_HPP

struct Point{
    double x, y;
};

class Ball{
    public:
        Ball (Point initialPos);
        void push(double v, double alpha);
        void fly(double t);
        Point position;
    private:
        double vx, vy;
};
#endif // BALL_HPP
//в остальном задача никак не отличается от предыдущей со структурами
