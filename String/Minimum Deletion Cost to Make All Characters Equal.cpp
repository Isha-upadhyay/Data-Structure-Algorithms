class Solution {
public:
    long long minCost(string s, vector<int>& cost) {

        long long n = cost.size();
        long long  totalSum = 0;
        vector<long long > freqCount(26, 0);
        for (int i=0;i<s.size();i++) {
            totalSum += cost[i];
            freqCount[s[i]- 'a'] += cost[i];
        }

        long long maxEle = 0;
        for (int i = 0; i < 26; i++) {
            maxEle = max(maxEle, freqCount[i]);
        }

        return totalSum - maxEle;
    }

};
