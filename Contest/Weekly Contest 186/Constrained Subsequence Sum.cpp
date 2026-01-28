class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> dp(n); // max subsequence sum end at i
        deque<int> dq;     // index of dp value

        int ans = nums[0];

        for (int i = 0; i < n; i++) {
            while (!dq.empty() &&
                   dq.front() <
                       i - k) { // remove index from dq which out of eindow
                dq.pop_front();
            }

            dp[i] = nums[i];
            if (!dq.empty()) {
                dp[i] += max(0, dp[dq.front()]);
            }

            while(!dq.empty() && dp[dq.back()] <= dp[i]){
                dq.pop_back();
            }

            dq.push_back(i);

            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

//
