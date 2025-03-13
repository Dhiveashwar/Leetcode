#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int left = 0, right = 0, maxLen = 0, maxFreq = 0;
        int hash[26] = {0}; // Initialize the array to store character frequencies
        int changes = 0;

        while (right < n) {
            maxFreq = max(maxFreq, ++hash[s[right] - 'A']);
            changes = (right - left + 1) - maxFreq;
            
            if (changes > k) {
                hash[s[left] - 'A']--;
                left++;
            }
            
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};

int main() {
    Solution sol;
    string s;
    int k;
    
    cout << "Enter the string: ";
    cin >> s;
    cout << "Enter the value of k: ";
    cin >> k;
    
    int result = sol.characterReplacement(s, k);
    cout << "The length of the longest substring after at most " << k << " replacements is: " << result << endl;
    
    return 0;
}