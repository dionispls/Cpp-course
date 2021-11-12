#include <iostream>
#include <vector>
using namespace std;

class Bullet{
private:
    int x;
    int y;
    int orient;
    int dmg;

public:
    Bullet(int x, int y, int dmg, int orient);
    bool movfrwd(string *mp, bool fr);
    pair<int, int> getcords();
    void collision(bool rf);
};
