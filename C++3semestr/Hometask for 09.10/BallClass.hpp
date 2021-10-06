#include "Ball.cpp"
#include "Ball.hpp"
#include <thread>
#include <iostream>

int main(){
    Point a;
    a.x = 2;
    a.y = 3;
    Ball orange_ball(a);
    orange_ball.push(10, 1);
    for (double t = 0; t < 10; t+=0.01){
        orange_ball.fly(t);
        std::cout << orange_ball.position.x << " " << orange_ball.position.y << "\n";
            }
}//в остальном задача никак не отличается от предыдущей со структурами
