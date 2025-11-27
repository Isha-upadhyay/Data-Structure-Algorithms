class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 1; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                if (nums[j] + nums[j - i] == target) { 
                    return {j - i, j};
                }
            }
        }
        return {}; // is our solution .
    }
};
