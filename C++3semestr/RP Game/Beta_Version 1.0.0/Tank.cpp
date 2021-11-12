#include "Tank.h"

Tank::Tank(int x = 0, int y = 0, int hp = 100 ,int dmg = 50, int chance_of_crit = 20, int chance_of_escape = 20, int add_xp = 50, int orient=1){
        this->x = x;
        this->y = y;
        this->hp = hp;
        this->orient = orient;
        this->dmg = dmg;
        this->chance_of_crit = chance_of_crit;
        this->chance_of_escape = chance_of_escape;
        this->add_xp = add_xp;
        xp = 0;
        level = 1;
        chg_lev = false;
}

void Tank::upd(vector<int> a){
    this->hp = a[0];
    this->dmg = a[1];
    this->chance_of_crit = a[2];
    this->chance_of_escape = a[3];
    this->add_xp = a[4];

}

void Tank::shoot(int orien){
        Bullet a(x, y, dmg, orien);
        Bullets.push_back(a);
}

void Tank::setcords(int x, int y){
        this->x = x;
        this->y = y;
}

void Tank::movfrwd(string *mp){
        switch(orient){
            case 1:
                if (mp[x-1][y] != 35)
                    x--;
                if (mp[x][y] == 42)
                    hp = 0;
                break;
            case 0:
                if (mp[x][y-1] != 35)
                    y--;
                if (mp[x][y] == 42)
                    hp =0;
                break;
            case 3:
                if (mp[x+1][y] != 35)
                    x++;
                if (mp[x][y] == 42)
                    hp = 0;
                break;
            case 2:
                if (mp[x][y+1] != 35)
                    y++;
                if (mp[x][y] == 42)
                    hp = 0;
                break;
        }
}

int Tank::gethp(){
        return hp;
}
void Tank::add_dmg(int a){
    dmg += a;
}

pair<int, int> Tank::getcords(){
        return make_pair(x, y);
    }

int Tank::getor(){
        return orient;
    }
int Tank::get_coe(int a = 0){
    chance_of_escape += a;
    return chance_of_escape;
}

int Tank::get_coc(int a = 0){
    chance_of_crit += a;
    return chance_of_crit;
}

int Tank::get_ax(int a = 0){
    add_xp += a;
    return add_xp;
}

void Tank::mov(int napr, string *mp){
        if (napr == orient)
            movfrwd(mp);
        else
            orient = napr;
    }

Tank MyTank(0,0);

