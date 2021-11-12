#include "Bullet.cpp"

class Enemy: public Tank{
    private:
        int orient;
        int dmg;
    public:
        int hp;
        Enemy ();
        vector<Bullet> Bullets;
        void shoot1(int orien);
        bool movfrwd1(string *mp);
};
