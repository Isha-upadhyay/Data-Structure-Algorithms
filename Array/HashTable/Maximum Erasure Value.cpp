class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> checked;

        int left = 0, right = 0;
        int curr_sum = 0, max_sum = 0;

        while (right < nums.size()) {
            while(checked.find(nums[right]) != checked.end()){
                checked.erase(nums[left]);
                curr_sum -= nums[left];
                left++;
            }

            curr_sum += nums[right];
            checked.insert(nums[right]);
            max_sum = max(max_sum, curr_sum);
            right++;
        }

        return max_sum;
    }
};
