class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
       
        int count = 0;
        for(int left = 0;left<nums.size();left++){
            int sum  = 0;
            unordered_set<int> st;
            for(int right = left;right < nums.size();right++){
                sum += nums[right];
                st.insert(nums[right]);
                if(st.count(sum)){
                    count++;
                }
                
            }
        }

        return count;
        
      
    }
};
