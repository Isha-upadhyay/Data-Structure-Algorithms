class Solution {
public:
    long long countStableSubarrays(vector<int>& v) {
        int n = v.size();
        vector<long long> pref(n);
        pref[0] = v[0];
        for (int i = 1; i < n; i++) pref[i] = pref[i - 1] + v[i];

        long long cnt = 0;
        unordered_map<long long, unordered_map<long long, long long>> mp;

        for (int i = 1; i < n; i++) {
            long long need = pref[i] - 2LL * v[i];
            cnt += mp[need][v[i]];
            mp[pref[i - 1]][v[i - 1]]++;
        }

        return cnt;
    }
};
