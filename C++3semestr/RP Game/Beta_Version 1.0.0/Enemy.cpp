#include "Enemy.h"
Enemy::Enemy (){
        orient = rand()%4;
        hp = 70 + rand() % 60;
        dmg = 8 + rand() % 10;
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
        if (rand()%5==0){//раз в 5 ходов стреляет
            shoot1(orient);}
        if (rand()%5 == 0)//чтобы менял направление
            orient = rand() %4;
        for (vector<Bullet>::iterator it = Bullets.begin(); it < Bullets.end(); it++){//рендерим движение всех пуль для данного танка
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
