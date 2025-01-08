class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int res = 0;
        for (int i = 0; i < words.size(); i++) {
            int n = words[i].size();
            // cout << words[i] << endl;
            for (int j = i + 1; j < words.size(); j++) {
                int ws = words[j].size();
                if (n > ws)
                    continue;
                // cout << words[j] << endl;
                bool prefix = true, suffix = true;
                for (int k = 0; k < n; k++) {
                    if (words[i][k] != words[j][k])
                        suffix = false;
                    if (words[i][n - k - 1] != words[j][ws - k - 1])
                        prefix = false;
                }
                if (suffix && prefix)
                    res++;
            }
        }
        return res;
    }
};
