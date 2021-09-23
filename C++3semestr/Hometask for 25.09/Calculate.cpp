#include <iostream>
#include <algorithm>
#include <vector>

double calculate(double a, double b,std::function<double(double, double)> c){
        return (c(a, b));
}
int main()
{
    double a, b;
    std::cin >> a >> b;
    std::vector<std::function<double(double, double)>> v;
    v.push_back([](double x, double y) { return x + y; });
    v.push_back([](double x, double y) { return x * y; });
    v.push_back([](double x, double y) { return x - y; });
    v.push_back([](double x, double y) { return x*x + y*y; });
    for(int i = 0; i < v.size(); i++)
        std::cout << calculate(a, b, v[i]) << " ";
    return 0;
}
