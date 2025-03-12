class Solution {
  public:
    int minCostClimbingStairs(vector<int>& cost) {
        // Write your code here
        int n = cost.size();
        int dp[n+2] = {0};
        for(int i=n-1;i>=0;i--){
            dp[i] = cost[i]+min(dp[i+1],dp[i+2]);
        }
        return min(dp[0],dp[1]);
    }
};
