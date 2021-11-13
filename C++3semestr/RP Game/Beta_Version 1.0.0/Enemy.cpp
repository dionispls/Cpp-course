#include "Enemy.h"
Enemy::Enemy (){
        orient = rand()%4;
        hp = 70 + rand() % 60;
        dmg = 20 + rand() % 10;
    }

void Enemy::shoot1(int orien){
        Bullet a(x, y, dmg, orien);
        Bullets.push_back(a);
}
bool Enemy::movfrwd1(string *mp){
        if (rand()%3 == 0){
            orient = rand() %4;
            return true;
        }
        if (rand()%5==0){//ðàç â 5 õîäîâ ñòðåëÿåò
            shoot1(orient);}
        for (vector<Bullet>::iterator it = Bullets.begin(); it < Bullets.end(); it++){//ðåíäåðèì äâèæåíèå âñåõ ïóëü äëÿ äàííîãî òàíêà
            bool f =(*it).movfrwd(mp, false);
            if (!f)
                it = Bullets.erase(it);
        }
        switch(orient){
    case 1:
        if (mp[x-1][y] != 35){
        x--;}
        else
        orient = rand() %4;
        break;
    case 0:
        if (mp[x][y-1] != 35){
        y--;}
        else{
        orient = rand() %4;}
        break;
    case 3:
        if (mp[x+1][y] != 35){
        x++;}
        else{
        orient = rand() %4;}
        break;
    case 2:
        if (mp[x][y+1] != 35){
        y++;}
        else{
        orient = rand() %4;}
        break;
    }

    }

vector<Enemy> Enemies;
