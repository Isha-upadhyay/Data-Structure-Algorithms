class Solution {
public:
    vector<int> computePi(const string &s){
        int n = s.size();
        vector<int> pi(n);

        for(int i=1, j=0;i<n;i++){
            while(j>0 && s[i] != s[j]){
                j = pi[j-1];
            }
            if(s[i] == s[j]){
                j++;
            }
            pi[i] = j;
        }
        return pi;
    }
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;

        string  S = needle + '#' + haystack;
        vector<int> pi = computePi(S);

        int needleLength = needle.size();

        for(int i=needleLength+1;i<S.size();i++){
            if(pi[i] == needleLength){
                return i-2*needleLength;
            }
        }
        return -1;
    }
};
