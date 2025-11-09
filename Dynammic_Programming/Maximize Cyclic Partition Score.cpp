class Solution {
public:
    long long maximumScore(vector<int>& nums, int k) {
        int n = nums.size();

        // 🔹 Step 1: Find index of minimum element (rotation start point)
        int j = 0;
        for (int i = 1; i < n; i++)
            if (nums[i] < nums[j]) j = i;

        // 🔹 Step 2: Build array 'a' (rotated starting from min element)
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            a[i] = nums[(j + i) % n];

        // 🔹 Step 3: Build array 'b' (rotated + reversed for opposite direction)
        vector<int> b(n);
        for (int i = 0; i < n; i++)
            b[i] = nums[(j + 1 + i) % n];
        reverse(b.begin(), b.end());

        // 🔹 Step 4: Compute maximum score from both directions
        return max(f(a, k), f(b, k));
    }

private:
    // 🔸 Helper function to calculate max score using DP
    long long f(vector<int>& a, int k) {
        int n = a.size();
        // dp[i][j] = max score using first j elements divided into i partitions
        vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, LLONG_MIN));

        long long mn = LLONG_MAX, mx = LLONG_MIN;

        // 🔹 Base case: only 1 partition -> difference between max and min
        for (int j = 0; j < n; j++) {
            mn = min<long long>(mn, a[j]);
            mx = max<long long>(mx, a[j]);
            dp[1][j + 1] = mx - mn;
        }

        long long res = dp[1][n]; // initial best result for 1 partition

        // 🔹 DP transition for 2 to k partitions
        for (int i = 2; i <= k; i++) {
            long long x = LLONG_MIN, y = LLONG_MIN;
            for (int j = i - 1; j < n; j++) {
                // Maintain running max of (dp[i-1][j] - a[j]) and (dp[i-1][j] + a[j])
                x = max(x, dp[i - 1][j] - a[j]);
                y = max(y, dp[i - 1][j] + a[j]);

                // Transition: choose the best among continuing or forming new partition
                dp[i][j + 1] = max(dp[i][j], max(x + a[j], y - a[j]));
            }
            res = max(res, dp[i][n]);
        }

        return res; // 🔸 Return best score possible
    }
};
