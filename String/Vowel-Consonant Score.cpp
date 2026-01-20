class Solution {
public:
    int vowelConsonantScore(string s) {
        int vCount = 0, cCount = 0;
        int score = 0;

        for (char ch : s) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vCount++;
            } else if (ch >= 'a' && ch <= 'z') {
                cCount++;
            }

            if (cCount > 0)
                score = floor(vCount / cCount);
            else
                score = 0;
        }
        return score;
    }
};
