#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversed_half = 0;
        while (x > reversed_half) {
            reversed_half = reversed_half * 10 + x % 10;
            x /= 10;
        }

        return x == reversed_half || x == reversed_half / 10;
    }
};

int main() {
    Solution sol;
    int num;

    std::cout << "Enter a number: ";
    std::cin >> num;

    if (sol.isPalindrome(num)) {
        std::cout << num << " is a palindrome.\n";
    } else {
        std::cout << num << " is not a palindrome.\n";
    }

    return 0;
}
