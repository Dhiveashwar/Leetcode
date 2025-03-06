#include <iostream>
using namespace std;

class shop {
    private:
        int money = 0;

    public:
        void modifyMoney() {
            money = money + 5;
        }

        int getMoney() {
            return money;
        }
};

int main() {
    shop S;
    S.modifyMoney();
    S.modifyMoney();

    cout << S.getMoney();
    return 0;
}
