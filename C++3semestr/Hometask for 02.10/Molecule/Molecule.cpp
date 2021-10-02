const double g = 9.8;
const double eps = 0.001;
#include <cmath>

#include "Molecule.hpp"

double quadratic(double a, double b, double c){
double det = b*b - 4*a*c;
if (det == 0)
    return (-b/(2*a));
else
    return ((-b-std::sqrt(det)) /(2*a));

}
Molecule::Molecule(Point initialPos){
    position = initialPos;
}

void Molecule::push(double v, double alpha){
    vx += v*std::cos(alpha);
    vy += v*std::sin(alpha);
}

bool Molecule::interact(Molecule another){
    if (std::abs(std::sqrt(position.x* position.x + position.y * position.y) - std::sqrt(another.position.x*another.position.x + another.position.y*another.position.y)) < eps){
        vx = -vx;
        vy = -vy;
        another.vx = -another.vx;
        another.vy = -another.vy;
            return 1;
    }
    return 0;
}
void Molecule::fly(double t){

position.x += vx*t;
position.y += vy*t;
if (position.x < eps){
     vx = -vx;
     position.x = 0;
} if (position.x> 100-eps){
    vx = -vx;
    position.x = 100;
}
if (position.y < eps){
     vy = -vy;
     position.y = 0;
} if (position.y> 100-eps){
    vy = -vy;
    position.y = 100;
}

}

