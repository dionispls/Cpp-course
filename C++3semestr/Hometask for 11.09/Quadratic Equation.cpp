#include <iostream>
#include <math.h>
using namespace std;

int main(){
float a,b,c,det;
cin >> a >>  b >> c;
det = b*b - 4*a*c;
if (det < 0)
    cout << "No roots:(";
else if (det == 0)
    cout << -b/(2*a);
else
    cout << (-b+sqrt(det)) /(2*a) << " " << (-b-sqrt(det)) /(2*a);
return 0;
}
