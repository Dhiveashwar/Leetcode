#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int x = matrix.size(), y = matrix[0].size();
        int low = 0, mid, high = x - 1, ans = -1;

        // Binary search to find the correct row
        while (low <= high) {
            mid = (low + high) / 2;
            if (matrix[mid][y - 1] >= target) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        // If target is not within matrix range
        if (ans == -1) return false;

        low = 0;
        high = y - 1;

        // Binary search within the identified row
        while (low <= high) {
            mid = (low + high) / 2;
            if (matrix[ans][mid] == target) return true;
            else if (matrix[ans][mid] > target) high = mid - 1;
            else low = mid + 1;
        }

        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int target;
    cout << "Enter target value: ";
    cin >> target;

    if (sol.searchMatrix(matrix, target)) {
        cout << "Target found in matrix.\n";
    } else {
        cout << "Target not found in matrix.\n";
    }

    return 0;
}
