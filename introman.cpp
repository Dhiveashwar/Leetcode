#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string hrns[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string ths[] = {"", "M", "MM", "MMM"};
        
        return ths[num / 1000] + hrns[(num % 1000) / 100] + tens[(num % 100) / 10] + ones[num % 10];
    }
};

int main() {
    Solution sol;
    int num;
    
    cout << "Enter an integer (1 to 3999): ";
    cin >> num;
    
    if (num < 1 || num > 3999) {
        cout << "Number out of range!" << endl;
    } else {
        cout << "Roman numeral representation: " << sol.intToRoman(num) << endl;
    }

    return 0;
}
