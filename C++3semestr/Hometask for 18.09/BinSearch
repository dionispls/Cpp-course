#include <iostream>
#include <vector>
#include <cmath>

bool binary_search(std::vector<int> v,int n,int x){
    int L = 0;
    int R = n - 1;
    while (L <= R){
        int m = floor((L + R) / 2);
        if (v[m] < x)
            L = m + 1;
        else if (v[m] > x)
            R = m - 1;
        else
            return 1;
    }
    return 0;
}


int main(){
    std::vector<int> v;
    int n = 50;
    int x;
    std::cout << "Enter the number to search for:" << "\n";
    std::cin >> x;
    for (int i = 0; i < n; i++)
        v.push_back(rand());
    int i = 1;
    while (i < n){
        int j = i;
    while ((j > 0) && (v[j-1] > v[j])){
        std::swap(v[j], v[j-1]);
        j = j - 1;
    }
    i++;
    }
    std:: cout << binary_search(v, n, x);
return 0;
}
