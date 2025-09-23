class Solution {
public:
    int balancedString(string s) {
        int n = s.size();
        int need = n / 4;
        unordered_map<int, int> count;
        for (int c : s)
            count[c]++;

            int ans = n;
            int left = 0;

        for (int right = 0; right < n; right++) {
            count[s[right]]--;

            while (left < n && count['Q'] <= need && count['W'] <= need &&
                   count['E'] <= need && count['R'] <= need) {

                ans = min(ans, right - left + 1);
                count[s[left]]++;
                left++;
            }
        }
        return ans;
    }
};
