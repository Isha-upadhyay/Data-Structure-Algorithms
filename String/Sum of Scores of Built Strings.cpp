using ll = long long;

class Solution {
public:

    
    vector<ll> find_lps(string& pattern){
        int m = pattern.length();
        vector<ll> lps(m, 0);
        int len = 0, i = 1;

        while(i < m){
            if(pattern[i] == pattern[len]){
                // Match found, increase length
                lps[i] = len + 1;
                len++;
                i++;
            }
            else{
                if(len != 0){
                    // Use previous LPS value
                    len = lps[len-1];
                }
                else{
                    // No match
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }

    
    long long sumScores(string s) {
        int n = s.length();

    
        vector<ll> lps = find_lps(s);

        vector<ll> dp(n, 0);
        ll ans = 0;

        for(int i = 0; i < n; i++){
            if(lps[i] == 0){
                dp[i] = 1;  // Single character match
            }
            else{
                dp[i] = dp[lps[i]-1] + 1;  
            }
            ans += dp[i];  
        }

        return ans;
    }
};
