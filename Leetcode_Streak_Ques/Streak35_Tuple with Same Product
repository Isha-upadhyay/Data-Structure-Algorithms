class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int numsLength = nums.size();
        sort(nums.begin(), nums.end());

        int totalNumberOfTuples = 0;

        // Iterate over all possible values for 'a'
        for (int aIndex = 0; aIndex < numsLength; aIndex++) {
            // Iterate over all possible values for 'b', starting from the end
            // of the array
            for (int bIndex = numsLength - 1; bIndex >= aIndex + 1; bIndex--) {
                int product = nums[aIndex] * nums[bIndex];

                // Use a hash set to store possible values of 'd'
                unordered_set<int> possibleDValues;

                // Iterate over all possible values for 'c' between 'a' and 'b'
                for (int cIndex = aIndex + 1; cIndex < bIndex; cIndex++) {
                    // Check if the product is divisible by nums[cIndex]
                    if (product % nums[cIndex] == 0) {
                        int dValue = product / nums[cIndex];

                        // If 'dValue' is in the set, increment the tuple count
                        // by 8
                        if (possibleDValues.find(dValue) !=
                            possibleDValues.end()) {
                            totalNumberOfTuples += 8;
                        }

                        // Add nums[cIndex] to the set for future checks
                        possibleDValues.insert(nums[cIndex]);
                    }
                }
            }
        }

        return totalNumberOfTuples;
    }
};
