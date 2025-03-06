# include <iostream>
#include <stdio.h> 
using namespace std;
class shop {
    private:
     int money;

    public:
    void modifyMoney() {
        money = money + 5;
    }

    int getMoney() {
        return money;
    }
};



int main () {
    shop S;
    S.modifyMoney();
    S.modifyMoney();

    cout << S.getMoney();
    return 0;
}