const double g = 9.8;
#include <cmath>

#include "Ball.hpp"

double quadratic(double a, double b, double c){
double det = b*b - 4*a*c;
if (det == 0)
    return (-b/(2*a));
else
    return ((-b-std::sqrt(det)) /(2*a));

}
Ball::Ball(Point initialPos){
    position = initialPos;
}

void Ball::push(double v, double alpha){
    vx += v*std::cos(alpha);
    vy += v*std::sin(alpha);
}

void Ball::fly(double t){

position.x += vx*t;
while (position.y + vy*t - g*t*t/2 < 0){
    double t1 = quadratic(-g/2, vy, position.y);
    vy -= g*t1;
    vy = -vy;
    t = t-t1;
    position.y = 0;
}
position.y += vy*t - g*t*t/2;
vy -= g*t;
}

