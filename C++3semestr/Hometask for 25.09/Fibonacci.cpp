#include <iostream>

unsigned long long int fibonacci(int n,unsigned long long int* a){
    if (a[n] != -1){
        return a[n];}
    else{
        a[n] = fibonacci(n-1, a) + fibonacci(n-2, a);
        return a[n];}
}


int main(){
    int n;
    std::cin >> n;
    unsigned long long int* a  = new unsigned long long int[n];
    for (size_t i = 0; i < n;i++)
        a[i] = -1;
    a[0] = 1;
    a[1] = 1;
    std::cout<<fibonacci(n-1, a);
    for (size_t i = 0; i < n;i++);
    return 0;
}
