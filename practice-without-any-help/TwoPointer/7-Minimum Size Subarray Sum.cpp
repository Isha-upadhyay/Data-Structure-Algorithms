class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int sum = 0;
        int ans = INT_MAX;

        for(int right = 0;right < nums.size();right++){
            sum+=nums[right];
            while(sum >= target){
                int length = right - left + 1;
                ans = min(ans, length);
                sum = sum - nums[left];
                left++;
            }
        }
        return (ans == INT_MAX)?0:ans;
        
    }
};
