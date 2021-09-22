#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b)
{
    if (a>b)
        return a;
      return b;
}

int lcs(vector<int> X,vector<int> Y, int m, int n )
{
    if (m == 0 || n == 0)
        return 0;
    if (X[m-1] == Y[n-1])
        return 1 + lcs(X, Y, m-1, n-1);
    else
        return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
}

int main()
{
    vector<int> X = {1,4,5,7,10};
    vector<int>Y = {5, 7, 8, 10};
    cout<<"Length of LCS is "<< lcs( X, Y, X.size(), Y.size() ) ;

    return 0;
}
