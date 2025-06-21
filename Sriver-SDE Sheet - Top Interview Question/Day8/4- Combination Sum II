class Solution {
public:
    void findCombination(int ind, int target, vector<int>& arr,
                         vector<vector<int>>& ans, vector<int>& ds) {
        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        for (int i = ind; i < arr.size(); i++) {
            // Skip duplicates
            if (i > ind && arr[i] == arr[i - 1])
                continue;

            // No need to go further if current value exceeds target
            if (arr[i] > target)
                break;

            ds.push_back(arr[i]);
            findCombination(i + 1, target - arr[i], arr, ans,
                            ds); // move to next index
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // to handle duplicates
        vector<int> ds;
        vector<vector<int>> ans;
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }
};
