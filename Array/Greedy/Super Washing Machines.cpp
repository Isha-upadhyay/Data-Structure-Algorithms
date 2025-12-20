class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n = machines.size();
        int total = 0;

        for (int x : machines) total += x;

        if (total % n != 0) return -1;

        int target = total / n;
        int prefixSum = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int balance = machines[i] - target;
            prefixSum += balance;
            ans = max(ans, max(abs(prefixSum), balance));
        }

        return ans;
    }
};
