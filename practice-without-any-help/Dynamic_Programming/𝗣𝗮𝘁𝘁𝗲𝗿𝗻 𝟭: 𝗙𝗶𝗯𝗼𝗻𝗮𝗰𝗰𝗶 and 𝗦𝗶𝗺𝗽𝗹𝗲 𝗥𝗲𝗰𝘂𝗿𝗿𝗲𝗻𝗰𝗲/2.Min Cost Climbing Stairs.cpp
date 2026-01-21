class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // int n = cost.size();
        // vector<int> dp(n);
        // dp[0] = cost[0];
        // dp[1] = cost[1];

        // for(int i=2;i<n;i++){
        //     dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        // }
        // return min(dp[n-1], dp[n-2]);

        // optimized version 
        int n = cost.size();

        int prev2 = cost[0];
        int prev1 = cost[1];

        for(int i=2;i<n;i++){
            int curr = cost[i] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        return min(prev1, prev2);

    }
};

