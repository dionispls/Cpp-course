#ifndef Ted
#include "Tank.cpp"
#define Ted 10
#include "Enemy.cpp"
#include <stdlib.h>

Bullet::Bullet(int x, int y, int dmg, int orient){
    this->orient = orient;
    this->dmg = dmg;
    this->x = x;
    this->y = y;
    }

bool Bullet::movfrwd(string *mp, bool fr){
        collision(fr);
        switch(orient){
            case 1:
                if (mp[x-1][y] != 35){
                    x--;
                }
                else
                    return false;
                break;
            case 0:
                if (mp[x][y-1] != 35){
                    y--;
                }
                else{
                    return false;
                }
                break;
            case 3:
                if (mp[x+1][y] != 35){
                    x++;
                }
                else{
                    return false;
                }
                break;
            case 2:
                if (mp[x][y+1] != 35){
                    y++;
                }
                else{
                    return false;
                }
                break;
            case 5:
                return false;
        }
        return true;
    }

pair<int, int> Bullet::getcords(){
        return make_pair(x, y);
    }

void Bullet::collision(bool rf){
        if (rf == 0){
            if (make_pair(Bullet::x, Bullet::y) == MyTank.getcords()){
                if (rand() % max(MyTank.get_coe(), 3) != 0)
                    MyTank.hp = MyTank.hp- dmg;
                Bullet::orient = 5;
                }}
        else{
        for (int i = 0; i < Enemies.size(); i++){
            if (make_pair(Bullet::x, Bullet::y) == Enemies[i].getcords()){
                MyTank.xp += MyTank.get_ax();
                if (MyTank.xp >= 125+75*MyTank.level){
                    MyTank.xp =MyTank.xp%(125+75*MyTank.level);
                    MyTank.level++;
                    MyTank.chg_lev = true;
                }
                if (rand() % max(MyTank.get_coc(), 3) == 0)
                    Enemies[i].hp -= Bullet::dmg;
                Enemies[i].hp -= Bullet::dmg;
                Bullet::orient = 5;}
        }
    }}
#endif // Ted
