#include <iostream>
#include <math.h>
using namespace std;

int main(){
int x, y;
cin >> x >> y;
y += x;
x = (y - x);
y = y - x;
cout << x << " " << y;

return 0;
}
