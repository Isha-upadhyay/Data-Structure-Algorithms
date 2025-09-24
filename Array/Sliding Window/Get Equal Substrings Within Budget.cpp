class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        
        int n = s.size();
        int left = 0, currCost = 0, maxLen = 0;
        
        for(int right=0;right<n;right++){
            currCost+= abs(s[right] - t[right]);
            
            if(currCost > maxCost){
                currCost-= abs(s[left] - t[left]);
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
