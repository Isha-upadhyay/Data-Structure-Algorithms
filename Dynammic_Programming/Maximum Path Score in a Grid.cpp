class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = -1;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k+1, -1)));

        dp[0][0][0] = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int cellC = grid[i][j] > 0?1:0;
                for(int cost = cellC; cost<=k;cost++){
                    if(dp[i][j][cost] == -1 && !(i==0 && j==0)) continue;

                    int val = dp[i][j][cost];

                    //move down
                    if(i+1 < m){
                        int nc = cost + (grid[i+1][j] > 0?1:0);
                        if(nc <= k)
                            dp[i+1][j][nc] = max(dp[i+1][j][nc], val + grid[i+1][j]);
                    }
                    // Move right
                    if (j + 1 < n) {
                        int nc = cost + (grid[i][j+1] > 0 ? 1 : 0);
                        if (nc <= k)
                            dp[i][j+1][nc] = max(dp[i][j+1][nc], val + grid[i][j+1]);
                    }
                }
            }
        }

        for(int c = 0;c<=k;c++){
            ans = max(ans, dp[m-1][n-1][c]);
        }
        return ans ;
        
    }
};
