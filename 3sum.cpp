#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; 
            if (nums[i] > 0) break;
            
            int st = i + 1, et = nums.size() - 1;
            int target = -nums[i];

            while (st < et) {
                int sum = nums[st] + nums[et];

                if (sum == target) {
                    ans.push_back({nums[i], nums[st], nums[et]});

                    
                    while (st < et && nums[st] == nums[st + 1]) st++;

                    
                    while (st < et && nums[et] == nums[et - 1]) et--;

                    st++;
                    et--;
                } 
                else if (sum > target) et--; 
                else st++;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = sol.threeSum(nums);

    for (const auto& triplet : result) {
        cout << "[";
        for (int i = 0; i < triplet.size(); i++) {
            cout << triplet[i];
            if (i != triplet.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }

    return 0;
}
