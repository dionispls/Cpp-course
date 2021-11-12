#include "Bullet.h"

class Tank{
private:
    int orient;
    int dmg;
    int add_xp;
    int chance_of_crit;
    int chance_of_escape;
public:
    void add_dmg(int a);
    bool chg_lev;
    int xp;
    int level;
    int hp;
    vector<Bullet> Bullets;
    int x;
    int y;
    Tank(int x, int y, int hp ,int dmg, int chance_of_crit, int chance_of_escape, int add_xp, int orient);
    void upd(vector<int> a);
    void shoot(int orien);
    void setcords(int x, int y);
    void movfrwd(string *mp);
    int gethp();
    pair<int, int> getcords();
    int getor();
    int get_coe(int a);
    int get_coc(int a);
    int get_ax(int a);
    void mov(int napr, string *mp);
};

