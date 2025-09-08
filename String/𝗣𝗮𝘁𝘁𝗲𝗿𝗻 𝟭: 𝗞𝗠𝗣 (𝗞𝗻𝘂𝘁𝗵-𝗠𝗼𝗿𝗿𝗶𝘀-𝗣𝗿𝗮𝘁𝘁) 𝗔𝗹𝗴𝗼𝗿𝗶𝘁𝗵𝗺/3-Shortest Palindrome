class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string l = s + "#" + rev; // special char to avoid overlap
        vector<int> lps(l.size(), 0);

        for (int i = 1; i < l.size(); i++) {
            int len = lps[i - 1];
            while (len > 0 && l[i] != l[len]) {
                len = lps[len - 1];
            }
            if (l[i] == l[len]) len++;
            lps[i] = len;
        }

        int longestPalPrefix = lps.back();
        string add = rev.substr(0, s.size() - longestPalPrefix);
        return add + s;
    }
};
