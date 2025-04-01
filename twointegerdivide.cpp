#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle edge case: INT_MIN divided by -1
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Determine the sign of the result
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;

        // Use long long to avoid overflow issues
        long long n = labs(dividend);
        long long d = labs(divisor);
        long long ans = 0;

        // Perform division using bit manipulation
        while (n >= d) {
            long long temp = d, count = 1;
            while (n >= (temp << 1)) {
                temp <<= 1;
                count <<= 1;
            }
            n -= temp;
            ans += count;
        }

        return sign * ans;
    }
};

int main() {
    Solution solution;
    int dividend, divisor;
    
    cout << "Enter dividend: ";
    cin >> dividend;
    cout << "Enter divisor: ";
    cin >> divisor;

    int result = solution.divide(dividend, divisor);
    cout << "Result: " << result << endl;

    return 0;
}
