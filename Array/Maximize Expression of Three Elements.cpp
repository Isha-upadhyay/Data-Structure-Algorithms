class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        
        int a = nums[n-1];
        int b = nums[n-2];
        int c = nums[0];
        
        
        
        return a + b - c;
    }
};
