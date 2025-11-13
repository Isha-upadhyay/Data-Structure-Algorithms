class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long n = nums.size();
        long long total = 0, F = 0;

        // Calculate F(0) and total sum
        for(int i = 0; i < n; i++) {
            total += nums[i];
            F += i * nums[i];
        }

        long long maxF = F;

        // Calculate F(k) using formula
        for(int k = 1; k < n; k++) {
            F = F + total - n * nums[n - k];
            maxF = max(maxF, F);
        }

        return (int)maxF;
    }
};
