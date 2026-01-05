class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        long long sum = 0;
        int count = 0;
        int minNeg = INT_MAX;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                
                if(matrix[i][j] < 0) count++;

                sum += abs(matrix[i][j]);
                minNeg = min(minNeg, abs(matrix[i][j]));
            }
        }

        if(count % 2 == 1) {
            sum -= 2 * minNeg;
        }

        return sum;
    }
};
