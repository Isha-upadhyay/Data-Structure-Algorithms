class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();

        sort(events.begin(), events.end(),
             [](auto& a, auto& b) { return a[0] < b[0]; });

        vector<int> suffixMax(n);
        suffixMax[n - 1] = events[n - 1][2];

        for (int i =  n - 2; i >= 0; i--) {
            suffixMax[i] = max(suffixMax[i + 1], events[i][2]);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int currentValue = events[i][2];
            int endTime = events[i][1];

            int low = i + 1;
            int high = n - 1;
            int idx = -1;

            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (events[mid][0] >= endTime + 1) {
                    idx = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            if (idx != -1) {
                currentValue += suffixMax[idx];
            }
            ans = max(ans, currentValue);
        }
        return ans;
    }
};
