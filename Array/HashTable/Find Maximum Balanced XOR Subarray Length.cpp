class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        
        unordered_map<long long, int> mp;

        long long prefixXOR = 0;
        int diff = 0;
        int n = nums.size();
        int ans = 0;

        long long key = (prefixXOR << 32) ^ (long long)diff;
        mp[key] = -1;

        for(int i=0;i<n;i++){
            prefixXOR ^= nums[i];



            if(nums[i] % 2 == 0) diff--;
            else diff++;


            long long key = (prefixXOR << 32) ^ (long long)diff;

            if(mp.count(key)){
                ans = max(ans, i - mp[key]);
            }else{
                mp[key] = i;
            }
        }

        return ans;


    }
};
