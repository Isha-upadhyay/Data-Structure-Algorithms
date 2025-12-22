class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        long long n = nums.size();

        //algorithm
        priority_queue<long long> pq;
        long long i = 0, ans = 0;
        while(i < n){
            pq.push(nums[i]);
            if(s[i] == '1'){
                ans += pq.top();
                pq.pop();
            }
            i++;
        }
        return ans;
    }
};
