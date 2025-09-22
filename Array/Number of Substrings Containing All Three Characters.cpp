class Solution {
public:
    int numberOfSubstrings(string s) {
         int n = s.size();
        vector<int> lastSeen(3, -1);
        int cnt = 0;
        
        for(int i = 0; i < n; i++) {
            // update last seen index for current char
            lastSeen[s[i] - 'a'] = i;

            // check if all three characters have been seen
            if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
                // add number of valid substrings ending at i
                cnt += 1 + min({lastSeen[0], lastSeen[1], lastSeen[2]});
            }
        }
        return cnt;

    }
};



// --------Sliding window approch ------
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int>lastSeen(3, 0);
        int left = 0, res = 0;

        for(int right = 0; right < n; right++){
            lastSeen[s[right] - 'a']++;

            while(lastSeen[0] > 0 && lastSeen[1] > 0 && lastSeen[2] > 0){
                res += s.size() - right;
                lastSeen[s[left] - 'a']--;
                left++;
            }
        }
        return res;

    }
};
