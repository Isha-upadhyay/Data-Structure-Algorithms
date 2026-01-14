class Solution {
public:
    long long countPairs(vector<string>& words) {

unordered_map<string, int> freq;
        long long count = 0;

        for(string &w : words){
            string pattern = "";
            for(int i = 1; i < w.size(); i++){
                int diff = (w[i] - w[i-1] + 26) % 26;
                pattern += to_string(diff) + ","; 
            }

            count += freq[pattern]; 
            freq[pattern]++;        
        }

        return count;
        
    }
};
