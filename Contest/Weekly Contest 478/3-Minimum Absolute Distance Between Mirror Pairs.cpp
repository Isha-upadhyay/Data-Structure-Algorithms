class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {

        vector<int> feri = nums;
        int n = feri.size();

        unordered_map<int, int> mp;

        for(int i=0;i<n;i++){
            mp[feri[i]] = i;
        }

        int ans = INT_MAX;

        for(int i=0;i<n;i++){
            int x = feri[i];
            int rev = 0;

            int temp = x;
            while(temp>0){
                rev = rev * 10 + (temp % 10);
                temp /= 10;
            }

            if(mp.count(rev)){
                int j = mp[rev];
                if(j > i){
                    ans = min(ans, j-i);
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
        
    }
};
