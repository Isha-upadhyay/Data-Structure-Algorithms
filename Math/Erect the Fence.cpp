class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        // sort 
        sort(trees.begin(), trees.end());
        vector<vector<int>> hull;

        auto cross = [](vector<int>& A, vector<int>& B, vector<int>& C){
            return (B[0] - A[0]) * (C[1] - A[1]) - (B[1]-A[1]) * (C[0] - A[0]);
        };

        // Lower Hull
        for(auto& p : trees){
            while(hull.size() >= 2 && cross(hull[hull.size() - 2], hull.back(), p) < 0) // turn right if its true then pop  last one
                hull.pop_back();
            hull.push_back(p);    
        }

        //Upper Hull
        int t = hull.size() + 1;
        for(int i=trees.size() - 1; i >= 0; i--){
            auto& p = trees[i];
            while(hull.size() >= t && cross(hull[hull.size()-2], hull.back(), p) < 0)
                hull.pop_back();
            hull.push_back(p);    
        }

        // remove duplicates
        sort(hull.begin(), hull.end());
        hull.erase(unique(hull.begin(), hull.end()) , hull.end());
        return hull;
    }
};
