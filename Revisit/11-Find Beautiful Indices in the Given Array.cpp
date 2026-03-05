class Solution {
    vector<int> prefix(const string& a) {
        int m = a.size();
        vector<int> table(m, 0);
        int j = 0;
        for (int i = 1; i < m; ++i) {
            while (j > 0 && a[i] != a[j]) 
                j = table[j - 1];
            
            if (a[i] == a[j]) 
                j++;
            table[i] = j;
        }

        return table;
    }

    vector<int> kmpSearch(const string& text, const string& a) {
        int n = text.size();
        int m = a.size();
        if (m == 0) {
            vector<int> result(n);
            iota(result.begin(), result.end(), 0);
            return result;
        }

        vector<int> table = prefix(a);
        vector<int> result;
        int j = 0;

        for (int i = 0; i < n; ++i) {
            while (j > 0 && text[i] != a[j]) 
                j = table[j - 1];

            if (text[i] == a[j])
                j++;
        

            if (j == m) {
                result.push_back(i - m + 1);
                j = table[j - 1];
            }
        }

        return result;
    }
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {

        vector<int> first = kmpSearch(s, a);
        vector<int> second = kmpSearch(s, b);
        int i = 0, j = 0;
        vector<int> result;

        while (i < first.size() && j < second.size()) {
            if (abs(first[i] - second[j]) <= k)
                result.push_back(first[i++]);
            else if (second[j] - first[i] > k) 
                i++;
            else 
                j++;
        }
        return result;
    }
};
