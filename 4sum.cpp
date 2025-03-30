#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < n; j++) {
                if (j > (i + 1) && nums[j] == nums[j - 1]) continue;

                int start = j + 1;
                int end = n - 1;

                while (start < end) {
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[start];
                    sum += nums[end];

                    if (sum == target) {
                        ans.push_back({nums[i], nums[j], nums[start], nums[end]});
                        int low = nums[start];
                        int high = nums[end];
                        start++, end--;

                        while (start < end && nums[start] == low) start++;
                        while (start < end && nums[end] == high) end--;
                    }
                    else if (sum > target) end--;
                    else start++;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> result = sol.fourSum(nums, target);

    cout << "Quadruplets with sum " << target << " are:\n";
    for (auto &quad : result) {
        for (int num : quad)
            cout << num << " ";
        cout << endl;
    }

    return 0;
}
