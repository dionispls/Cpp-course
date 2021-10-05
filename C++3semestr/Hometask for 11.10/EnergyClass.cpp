#include <iostream>
#include <cmath>

const long long int between = 10000000;
const int ev = 6.242;
class Energy{
    public:
        bool flag = 0;
        double value_in_joules;
        void read_in_joules(){
            std::cin >> value_in_joules;
            flag = 1;
        }
        void read_in_ergs(){
            long double a;
            std::cin >> a;
            value_in_joules = a/between;
        }
        void read_in_ev(){
             long double a;
            std::cin >> a;
            value_in_joules = a/ev/pow(10,18);
        }
        void show(){
            if (flag){
                std::cout <<"Value in joules: " <<value_in_joules << "\n";
                std::cout <<"Value in ergs: " <<value_in_joules * between << "\n";
                std::cout <<"Value in electron-volts: " <<value_in_joules * pow(10, 18) * ev<< "\n";}
            else
                std::cout<< "There has not been a value assigned yet.Please run the read function first." << "\n"};
        }

};
int main(){
    std::cout << "Enter number to interact: 1-show value; 2 - read in joules; 3 - read in ergs; 4 - read in ev; 0 - exit" << "\n";

    Energy test;
    bool work = 1;
    while (work){
        int a;
        std::cin >> a;
        if (a == 0)
            work = 0;
        else
            if (a==1)
                test.show();
            else
                if (a==2)
                    test.read_in_joules();
                else
                    if(a == 3)
                        test.read_in_ergs();
                    else
                        if (a==4)
                            test.read_in_ev();
                        else
                            std::cout << "Wrong value, enter another one"<< "\n\;


    }
return 0;
}

