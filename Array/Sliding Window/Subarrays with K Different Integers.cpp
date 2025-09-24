class Solution {
public:
    long long atMostK(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int,int> freq; // number -> frequency
    long long ans = 0;
    int left = 0;

    for (int right = 0; right < n; right++) {
        freq[nums[right]]++;

        // Agar distinct count k se zyada ho jaye toh shrink window
        while ((int)freq.size() > k) {
            freq[nums[left]]--;
            if (freq[nums[left]] == 0) {
                freq.erase(nums[left]);
            }
            left++;
        }

        // Ab current window me at most k distinct hai
        // To sab subarrays jo right par khatam ho rahe hai add karo
        ans += (right - left + 1);
    }

    return ans;
}

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};
