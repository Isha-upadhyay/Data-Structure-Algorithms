class Solution {
public:
    int residuePrefixes(string s) {
        int ans = 0;
        int distinct = 0;
        vector<bool> seen(26, false);
        for (int i = 0; i < s.size(); i++) {
            if (!seen[s[i] - 'a']) {
                distinct++;
                seen[s[i] - 'a'] = true;
            }

            if ((i + 1) % 3 == distinct) {
                ans++;
            }
        }
        return ans;
    }
};
