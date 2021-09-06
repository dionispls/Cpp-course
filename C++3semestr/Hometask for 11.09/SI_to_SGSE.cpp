#include <iostream>
#include <math.h>
using namespace std;

int main(){
cout << "1. Кулон -> Франклин" <<  " 2. Ампер -> СтатАмпер" << " 3. Вольт -> СтатВольт"  << " 4. Ом -> Секунда/Сантиметр";
cout << "Выберите цифру:";
int a, c = 299792458;
float b;
cin >> a;
while ((a>4) or (a<1)){
    cout << "Неправильное число, попробуйте еще раз";
    cin >> a;
}
cout << "Введите число, которое хотите перевести.";
cin >> b;
if (a <3)
    cout << b * c * 10;
else if (a == 3)
    cout << b / c * 1000000;
else
    cout << b * c * c / 1000000000;

return 0;
}
