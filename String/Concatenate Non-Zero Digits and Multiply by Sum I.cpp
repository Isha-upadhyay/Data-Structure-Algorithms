#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long sumAndMultiply(long long n) {
        string s = to_string(n);
        if (n < 0) s = s.substr(1);

        vector<char> a;
        for (char i : s) {
            if (i != '0') a.push_back(i);
        }

        if (a.empty()) return 0LL;

        long long sm = 0;
        for (char i : a) {
            sm += (i - '0');
        }

        string jn;
        jn.reserve(a.size());
        for (char i : a) jn.push_back(i);

        long long concat = stoll(jn);      
        return sm * concat;                  
    }
};
