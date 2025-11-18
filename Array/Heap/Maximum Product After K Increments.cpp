class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int num:nums){
            minHeap.push(num);
        }

        while(k-->0){
            int val = minHeap.top();
            minHeap.pop();
            minHeap.push(val + 1);
        }

        long long ans = 1;
        int MOD = 1e9 + 7;

        while(!minHeap.empty()){
            ans = ans * (minHeap.top()) % MOD;
            minHeap.pop();
        }

        return ans;
    }
};
