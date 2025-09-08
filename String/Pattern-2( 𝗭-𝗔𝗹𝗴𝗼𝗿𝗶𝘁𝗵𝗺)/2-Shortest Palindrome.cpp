class Solution {
public:
   // Z-algorithm function
vector<int> computeZ(const string &s) {
    int n = s.size();
    vector<int> Z(n, 0);
    int L = 0, R = 0;
    for (int i = 1; i < n; i++) {
        if (i <= R) {
            int k = i - L;
            Z[i] = min(Z[k], R - i + 1);
        }
        while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]]) {
            Z[i]++;
        }
        if (i + Z[i] - 1 > R) {
            L = i;
            R = i + Z[i] - 1;
        }
    }
    return Z;
}

string shortestPalindrome(string s) {
    string rev_s = s;
    reverse(rev_s.begin(), rev_s.end());
    string combined = s + '#' + rev_s;

    vector<int> Z = computeZ(combined);

    // find the max Z value starting in rev_s part
    int maxLen = 0;
    for (int i = (int)s.size() + 1; i < (int)combined.size(); i++) {
        if (Z[i] == (int)combined.size() - i) {
            maxLen = Z[i];
            break; // first such match from left is enough
        }
    }

    string add = rev_s.substr(0, s.size() - maxLen);
    return add + s;
}
};
