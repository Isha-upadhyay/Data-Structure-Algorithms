class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int m = arr1.size();
        int n = arr2.size();
        sort(arr2.begin(), arr2.end());
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            int left = 0, right = n-1, x = arr1[i] - d, y = arr1[i] + d;
            
            while (left <= right) {
                int mid = left + (right-left)/2;
                if (arr2[mid] < x) {
                    left = mid + 1;
                } 
                else if (arr2[mid] > y) {
                    right = mid - 1;
                } 
                else {
                    cnt++; break;
                }
            }
        }
        return m - cnt;
    }
};
