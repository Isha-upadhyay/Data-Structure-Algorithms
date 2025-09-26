class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(), ages.end());
        int n = ages.size();
        int ans = 0;

        int left = 0, right = 0;

        for (int i = 0; i < n; i++) {
            int age = ages[i];
            if (age < 15) continue;

            while (left < n && ages[left] <= 0.5 * age + 7)
                left++;

            while (right < n && ages[right] <= age)
                right++;

            ans += (right - left - 1);
        }

        return ans;
    }
    

};
