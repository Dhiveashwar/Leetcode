#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> num_to_index; 

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (num_to_index.find(complement) != num_to_index.end()) {
                
                return {num_to_index[complement], i};
            }
         
            num_to_index[nums[i]] = i;
        }

        return {};
    }
};

int main() {
    Solution solution;

    std::vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    std::vector<int> result1 = solution.twoSum(nums1, target1);
    std::cout << "Output: [" << result1[0] << ", " << result1[1] << "]" << std::endl;

    std::vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    std::vector<int> result2 = solution.twoSum(nums2, target2);
    std::cout << "Output: [" << result2[0] << ", " << result2[1] << "]" << std::endl;

    std::vector<int> nums3 = {3, 3};
    int target3 = 6;
    std::vector<int> result3 = solution.twoSum(nums3, target3);
    std::cout << "Output: [" << result3[0] << ", " << result3[1] << "]" << std::endl;

    return 0;
}
