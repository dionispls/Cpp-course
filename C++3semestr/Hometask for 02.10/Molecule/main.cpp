#include "Molecule.cpp"
#include "Molecule.hpp"
#include <thread>
#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>
#include <windows.h>
Point rndpoint(){
    Point a;
    a.x = rand()% 100;
    a.y = rand()%100;
    return a;
}


int main(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    srand(time(0));
    int n = 5;
    std::vector <Molecule> arr;
    for (int i = 0; i< n; i++){
        Molecule a(rndpoint());
        arr.push_back(a);
        arr[i].push(rand()%100, rand()%100);
    }
    for (double t = 0; t < 0.5; t+=0.0001){
            std::cout << "Time is: " << t << "\n";
            for (int i = 0; i < n; i++){
                arr[i].fly(t);
                for (int j = 0; j < n;j++){
                    if (i!=j){
                        bool check = arr[i].interact(arr[j]);
                        if (check){
                            SetConsoleTextAttribute(hConsole, 10);
                            std::cout << "There has been an interaction between " << i+1<< " molecule and " << j+1 << " molecule" << "\n";
                            SetConsoleTextAttribute(hConsole, 15);
                        }
                        }
                }
                std::cout <<i+1<<": "<< arr[i].position.x << " " << arr[i].position.y << "\n";}
            }
        std::cout << "\n";;
}
