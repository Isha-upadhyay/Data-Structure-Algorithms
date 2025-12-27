class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();

        vector<int> prefixN(n + 1, 0);
        vector<int> prefixY(n + 1, 0);

        // Prefix sum build
        for (int i = 1; i <= n; i++) {
            prefixN[i] = prefixN[i - 1];
            prefixY[i] = prefixY[i - 1];

            if (customers[i - 1] == 'N')
                prefixN[i]++;
            else
                prefixY[i]++;
        }

        int totalY = prefixY[n];
        int best = INT_MAX;
        int ans = 0;

        // Try all closing hours
        for (int j = 0; j <= n; j++) {
            int penalty = prefixN[j] + (totalY - prefixY[j]);

            if (penalty < best) {
                best = penalty;
                ans = j;
            }
        }

        return ans;
    }
};
