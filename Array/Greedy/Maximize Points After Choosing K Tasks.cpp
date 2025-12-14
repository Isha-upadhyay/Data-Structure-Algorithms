class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        
        int n = technique1.size();
        long long total = 0;
        vector<int> diff;

        // Step 1: Assume all tasks done with technique2
        for (int i = 0; i < n; i++) {
            total += technique2[i];
            diff.push_back(technique1[i] - technique2[i]);
        }

        // Step 2: Sort differences in descending order
        sort(diff.begin(), diff.end(), greater<int>());

        // Step 3: Pick at least k tasks for technique1
        for (int i = 0; i < k; i++) {
            total += diff[i];
        }

        // Step 4: Pick extra positive gains (optional but greedy optimal)
        for (int i = k; i < n; i++) {
            if (diff[i] > 0)
                total += diff[i];
            else
                break;
        }

        return total;
    }
};


// tec1 , tec2 
// ith task com -> tec1 - points - tech[i]
//if task complete - tech2[i] - tech2[i]
// k - min no. of task to complete uing tech 1
//rem - any tech
// total points earns ?
