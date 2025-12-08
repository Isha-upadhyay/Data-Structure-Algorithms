class Solution {
public:
    string toBinary(int x) {
        string s = "";
        while (x) {
            s += (x % 2) + '0';
            x /= 2;
        }
        return s;
    }
    bool isPalindrome(int x) {
        string bin = toBinary(x);
        string rev = bin;
        reverse(rev.begin(), rev.end());
        return bin == rev;
    }
    vector<int> minOperations(vector<int>& nums) {
        vector<int> palindromes;
        for (int i = 1; i <= 5000; i++) {
            if (isPalindrome(i))
                palindromes.push_back(i);
        }
        vector<int> ans;
        for(int& num : nums){
            int closest = 5000;
            auto fBigger = upper_bound(palindromes.begin(), palindromes.end(), num);
            if(fBigger != palindromes.end()) closest = *fBigger - num;
            if(fBigger != palindromes.begin()){
                closest = min(closest, num - *prev(fBigger));
            }
            ans.push_back(closest);
        }
        return ans;
    }
};
