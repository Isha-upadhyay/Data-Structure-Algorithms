class Solution {
public:
    int minLengthAfterRemovals(string s) {

        int count_a = 0, count_b = 0;
        for (char ch : s) {
            if (ch == 'a')
                count_a++;
            else
                count_b++;
        }

        if (count_a == count_b)
            return 0;
        if(count_a == 0 || count_b == 0) return s.size();
        return abs(count_a - count_b);
    }
};
