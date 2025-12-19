class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n = tasks.size();


        unordered_map<int, int> mp;
        for(int task:tasks){
            mp[task]++;
        }
        int rounds = 0;
        
        for(auto &it : mp){
           int count = it.second;

           if(count == 1) return -1;

            rounds += count / 3;
            if (count % 3 != 0) rounds++;
        }
        

        

        return rounds;
    }
};
