#include <iostream>
#include <algorithm>
#include <vector>


int main()
{
    int n;
    std::vector<int> a;
    std::cin >> n;
    for (int i = 0; i < n; i++){
      int b;
      std::cin >> b;
      a.push_back(b);
    }
    //descend
    std::sort(a.begin(), a.end(),
        [](int a, int b) {
            return (a < b);
        }
    );

    for(int i = 0; i < a.size(); i++)
        std::cout << a[i] << " ";
    std::cout << "\n";
    //ascend
   std::sort(a.begin(), a.end(),
        [](int a, int b) {
            return (a > b);
        }
    );

    for(int i = 0; i < a.size(); i++)
        std::cout << a[i] << " ";
    std::cout << "\n";
    return 0;
}
