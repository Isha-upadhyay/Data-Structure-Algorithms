class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {

        int size;
        for (size = nums.size()-1; size>0; size--){
            if (nums[size]<=nums[size-1]) break;
        }
        return size;


        
    }
};
