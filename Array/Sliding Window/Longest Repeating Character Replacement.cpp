class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, right = 0, maxLen = 0, maxFreq = 0;

        vector<int> mpp(26, 0);

        while(right < s.size()){
            mpp[s[right] - 'A']++;
            maxFreq = max(maxFreq,  mpp[s[right] - 'A']);

            if((right - left + 1) - maxFreq > k){ // replced value is greater then k
                mpp[s[left] - 'A']--;
                left++;
            }

            if((right - left + 1) - maxFreq <= k){ // replace value is less then or qual to k
                maxLen = max(maxLen , right - left + 1);
                right++;
            }
        }
        return maxLen;
    }
};
