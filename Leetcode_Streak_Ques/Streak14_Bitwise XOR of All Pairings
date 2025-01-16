class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        
        int n1=nums1.size();
        int n2=nums2.size();
        int ans=0;

        if(n2%2>0)
        {
            for(auto it:nums1)
            {
                ans^=it;
            }
        }


        if(n1%2>0)
        {
            for(auto it:nums2)
            {
                ans^=it;
            }
        }

        return ans;
    }
};
