    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(int num:nums){
            mp[num]++;

            if(mp[num] > 1) return true;
        }
        return false;
    }
};
