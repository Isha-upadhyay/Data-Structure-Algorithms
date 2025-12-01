class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long low = 0, high = 0;

        for (long long b : batteries)
            high += b;  

        high /= n; 

        long long ans = 0;

        while (low <= high) {
            long long mid = (low + high) / 2;

            long long total = 0;
            for (long long b : batteries)
                total += min(b, mid);

            if (total >= mid * n) {
                ans = mid; 
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
