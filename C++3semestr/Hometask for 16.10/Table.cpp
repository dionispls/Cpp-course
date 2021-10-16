#include <iostream>
#include <vector>
using namespace std;

class Table{
    public:
        vector<int> id;
        vector<int> value;
    void push(int value){
        id.push_back(id.size());
        this->value.push_back(value);
    }
    int pop(){
        int a = *(value.end()-1);
        value.pop_back();
        id.pop_back();
        return a;
    }
    Table operator +(Table t2){
        Table ans;
        for(int i = 0; i < value.size(); i++)
            ans.push(value[i]);
        for(int i = 0; i < t2.value.size(); i++)
            ans.push(t2.value[i]);
        return ans;
    }
    friend Table operator ++(Table &t, int){
        t.id.push_back(t.id.size());
        t.value.push_back(0);
        return t;
    }
    int operator [](int id){
        return value[id];
    }
    friend ostream& operator << (ostream &out, const Table &t){
        for(int i = 0; i< t.id.size(); i++){
            out << t.id[i] << ' '<<t.value[i] << endl;
        }
    }
};

int main(){
    Table t;
    Table k;
    k.push(4);
    t.push(5);
    t.push(6);
    t.push(7);
    Table ans = k + t;
    ans++;
    cout << ans;
    cout << ans[2]<<endl;
    cout << ans.pop() << endl;
    cout << ans<< endl;
    return 0;
}
