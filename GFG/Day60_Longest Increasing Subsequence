class Solution {
  public:
    int lis(vector<int>& arr) {
        // code here
        vector<int> ans;
        ans.push_back(arr[0]);
        for(int i=1;i<arr.size();i++){
            if(arr[i]>ans.back())ans.push_back(arr[i]);
            else ans[lower_bound(ans.begin(),ans.end(),arr[i])-ans.begin()]=arr[i];
        }
        return ans.size();
    }
};
