#include "all_includes.h"
using namespace std;


int main(){
    string name;
    int j = 0;
    int cur, cur1;
    string mp[13];//карта
    bool it = true;
    vector<int> stats = {100, 50, 20, 20, 50};
    vector<string> TankVariants = {"T-34 (higher Hp)", "T-54 (higher Damage)", "T-90 (Higher Chance of Crit)", "T-95 (higher Chance of Escape)", "T-14 (higher Xp gained per kill)"};//вектор танкa
    vector<string> MapVariants = {"Mirage", "Dune", "Inferno", "Cache", "Overpass", "Dust II", "Nuke", "BOSS"};//вектор карт

    cout << "Press \'q\' to quit, press any other key to continue";
     if (getch() == 113) //нажатие q отменяет игру
            return 0;
    clr; //очищает экран
    cout << "Enter your name" << endl;
    cin >> name;
    clr; //очищает экран

    while (it){//Выбор танка
    cout << "Hello, " << name << "! Welcome to Student WOT. Please select your tank:" <<endl;
    cout<< "(Up and down arrow to navigate, Enter to select, q to quit)"<<endl;
    for(int i = 0; i< TankVariants.size(); i++){//выбор танка
        if (i == j%TankVariants.size()){
            cout << dye::green(TankVariants[i]) <<endl;//танка, который сейчас выбран подсвечен зеленым
        }
        else{
        cout << TankVariants[i] <<endl;}
    }
    int c = getch();
    switch(c){
    case 72://верхняя стрелка
        j--;
        clr; //очищает экран
        break;
    case 80://нижняя стрелка
        j++;
        clr; //очищает экран
        break;
    case 13://кнопка enter
            cur = j;
            clr;
            it = false;
            break;
    case 113: //нажатие q отменяет игру
            return 0;
    default:
        clr;
        break;

    }}

    cur = (cur + TankVariants.size()*1000) % TankVariants.size();
    switch(cur){
    case 0:
        stats[0]+=50;
        break;
    case 1:
        stats[1] += 10;
        break;
    case 2:
        stats[2] -= 5;
        break;
    case 3:
        stats[3] -= 5;
        break;
    case 4:
        stats[4] += 25;
        break;
    }
    MyTank.upd(stats);

    map_selection://выбор карты, сюда если что возвращаемся
    j = 0;
    it = true;

    while(it){//аналогично танкам
        cout << "Please, select a map :" <<endl;
        for(int i = 0; i< MapVariants.size(); i++){
        if (i == j%MapVariants.size()){
            cout << dye::green(MapVariants[i]) <<endl;
        }
        else{
        cout << MapVariants[i] <<endl;}
    }
    int c = getch();
    switch(c){
    case 72:
        j--;
        clr; //очищает экран
        break;
    case 80:
        j++;
        clr; //очищает экран
        break;
    case 13:
            cur1 = j;
            clr;
            it = false;
            break;
    case 113: //нажатие q отменяет игру
            return 0;
    default:
        clr;
        break;

    }}

    for (int i = 3; i > 0;i--){//загрузка
    cout << "Starting in " << i << "..."<<endl;
    Sleep(800);
    clr; //очищает экран
    }

    cur1 = (cur1 + MapVariants.size()*100)%MapVariants.size();//костыль от негативного j
    cur1++;
    stringstream ss;//делаем из cur1 string
    ss<<cur1;
    string s;
    ss>>s;
    ifstream F;
    F.open("Maps\\Map"+s+".txt");//загрузка нужной карты
    for (int i = 0;i <13; i++)
        F>>mp[i];//сохраняем карту в массив
    F.close();

    for (int i = 0;i <13; i++){//иницилизируем поле
            for(int tr = 0; tr< 31; tr++){
                switch(mp[i][tr]){
            case 35:{
                cout << "#";
                break;}
            case 95:{
                cout << " ";
                break;}
            case 42:{
                cout << dye::red("*");//мина
                break;}
            case 101:{
                Enemy atr;
                atr.setcords(i, tr);
                Enemies.push_back(atr);//заводим врага с нужными координатами и сохраняем в списке врагов
                cout << dye::red("e");
                break;}
            case 84:
                MyTank.setcords(i, tr);//задаем нашему танку координаты, создан он глобально
                cout << dye::green("^");
                break;
                }}
                cout << endl;
        }
        cout << endl;
        cout << " " << name <<" "<< TankVariants[cur] << " HP: " << MyTank.gethp() << " Enemies left:" << Enemies.size() << " xp: "<< MyTank.xp <<"/" << MyTank.level*75+125<< " Level: " << MyTank.level << endl;
//выводим информацию про танк/игру
    it = true;
    while (it){
        ending:
            if (MyTank.chg_lev){//проверка на то, нужно ли обновить какой-либо навык
                cout << dye::green("You have upgraded from level ") << dye::green(MyTank.level - 1);
                cout<< dye::green(" to " )<< dye::green(MyTank.level)<<endl;
                cout << "Press 1- to upgrade damage, 2-to upgrade max health, 3-to upgrade Chance of Crit, 4-to upgrade Chance of Escape"<<endl;
                bool it1 = true;
                while(it1){
                    int c = getch();
                    switch(c){
                case 49:
                    it1 = false;
                    MyTank.add_dmg(20);
                    cout<<"You can continue playing by pressing any key";
                    break;
                case 50:
                    it1 = false;
                    MyTank.hp+= 50;
                    cout<<"You can continue playing by pressing any key";
                    break;
                case 51:
                    it1 = false;
                    MyTank.get_coc(-2);
                    cout<<"You can continue playing by pressing any key";
                    break;
                case 52:
                    it1 = false;
                    MyTank.get_coe(-2);
                    cout<<"You can continue playing by pressing any key";
                    break;
                default:
                    break;

                    }
                }
            MyTank.chg_lev = false;
            }
        int c = getch();
        switch(c){//наше действие
        case 72:
            MyTank.mov(1, mp);
            break;
            /*
        case 125:
            while(Enemies.size()>0){
                Enemies.erase(Enemies.begin());
            }
            break;
            */
        case 80:
            MyTank.mov(3, mp);
            break;
        case 75:
            MyTank.mov(0, mp);
            break;
        case 77:
            MyTank.mov(2, mp);
            break;
        case 32:
            MyTank.shoot(MyTank.getor());
            break;
        case 113:
            return 0;
            break;
         default:
            goto endr;
            break;
        }
        for (vector<Bullet>::iterator it = MyTank.Bullets.begin(); it < MyTank.Bullets.end(); it++){
            bool f =(*it).movfrwd(mp, true);//двигаем все пули нашего танка, при необходимости их удаляем
                if (!f)
                    it = MyTank.Bullets.erase(it);
        }
         for (int tre = 0; tre< Enemies.size(); tre++){
                    Enemies[tre].movfrwd1(mp);//всех врагов двигаем и иногда они стреляют
                    Enemies[tre].shoot1(1);
         }
        endr:
            clr; //очищает экран
        pair<int, int> cords = MyTank.getcords();
        if (MyTank.gethp()){
        for (int i = 0;i <13; i++){//рисуем поле
            for(int tr = 0; tr< 31; tr++){
                if (make_pair(i, tr) == cords){
                 int r = MyTank.getor();
                 switch(r){
             case 0:
                cout << dye::green("<");
                break;
             case 1:
                cout << dye::green("^");
                break;
             case 2:
                cout << dye::green(">");
                break;
             case 3:
                cout << dye::green("v");
                break;
                 }
                }else{
                    bool ind = 1;
                for (vector<Bullet>::iterator it = MyTank.Bullets.begin(); it < MyTank.Bullets.end(); it++){
                    if(make_pair(i, tr) == (*it).getcords()){
                        cout << dye::green(".");
                        ind = 0;
                        goto drawmap;
                        }
                }
                for (int tre = 0; tre< Enemies.size(); tre++){
                    if((make_pair(i, tr) == Enemies[tre].getcords())){
                            if(Enemies[tre].hp >0){
                                cout << dye::red("e");
                                ind = 0;
                                goto drawmap;}
                            else{
                                Enemies.erase(Enemies.begin()+tre);
                                tre--;}
                    }
                    else{for(vector<Bullet>::iterator it = Enemies[tre].Bullets.begin(); it < Enemies[tre].Bullets.end(); it++){
                    if(make_pair(i, tr) == (*it).getcords()){
                        cout << dye::red(".");
                        ind = 0;
                        goto drawmap;
                        }}
                        }}
            drawmap:
            if (ind)
                switch(mp[i][tr]){
            case 35:{
                cout << "#";
                break;}
            case 95:{
                cout << " ";
                break;}
            case 42:{
                cout << dye::red("*");
                break;}
            case 101:{
                cout << " ";
                break;}
            case 84:
                cout << " ";
                break;
                }}}
                cout << endl;
        }
        cout << endl;
        cout << " " << name <<" "<< TankVariants[cur] << " HP: " << MyTank.gethp() << " Enemies left:" << Enemies.size() << " xp: "<< MyTank.xp <<"/" << MyTank.level*75+125<<" Level: " << MyTank.level << endl;}
        else{
            cout << dye::red("You died, sorry:(");
            it = false;
        }
        if (Enemies.size() == 0){
            clr;
            cout << dye::green(" Congrats, ") << dye::green(name) << dye::green("! You won!") << endl;
            Sleep(500);
            cout << "You can play another map or quit(press any key to continue, q-to quit)"<< endl;
            int c = getch();
            switch(c){
        case 113:
            return 0;
        default:
            clr;
            goto map_selection;
            }
                }
}

return 0;
}
