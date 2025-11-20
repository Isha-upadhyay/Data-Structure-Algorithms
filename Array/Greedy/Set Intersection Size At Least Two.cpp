class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            if (a[1] != b[1]) return a[1] < b[1];
            return a[0] > b[0];
        });

        int last1 = -1, last2 = -1;
        int ans = 0;

        for (auto &in : intervals) {
            int s = in[0], e = in[1];
            int cnt = 0;

            if (last1 >= s && last1 <= e) cnt++;
            if (last2 >= s && last2 <= e) cnt++;

            if (cnt == 2) continue;
            if (cnt == 1) {
                ans++;
                last2 = last1;
                last1 = e;
            } else {
                ans += 2;
                last2 = e - 1;
                last1 = e;
            }
        }
        return ans;
    }
};
