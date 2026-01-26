class Solution {
public:
    string lexSmallestAfterDeletion(string s) {

        int remainingCount[26] = {0};   
        int usedCount[26] = {0};        

        
        for (char ch : s) {
            remainingCount[ch - 'a']++;
        }

        string result; 

        for (char ch : s) {
            int currIdx = ch - 'a';

            
            remainingCount[currIdx]--;

            
            while (!result.empty()) {
                char lastChar = result.back();
                int lastIdx = lastChar - 'a';

                
                if (lastChar > ch &&
                    (remainingCount[lastIdx] > 0 || usedCount[lastIdx] > 1)) {

                    result.pop_back();
                    usedCount[lastIdx]--;
                } else {
                    break;
                }
            }

            
            result.push_back(ch);
            usedCount[currIdx]++;
        }

        // Extra duplicates ko end se hata do (lexicographically safe)
        while (!result.empty() && usedCount[result.back() - 'a'] > 1) {
            usedCount[result.back() - 'a']--;
            result.pop_back();
        }

        return result;
    }
};
