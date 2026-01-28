class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        //case 1 - when k == n, take all card
        if(k==n) return accumulate(cardPoints.begin(), cardPoints.end(), 0);

        int totalSum = 0;
        for(int  x:cardPoints){
            totalSum += x;
        }

        int windowSize = n - k;
        int windowSum = 0;

        for(int i=0;i<windowSize;i++){
            windowSum += cardPoints[i];
        }

        int minWindowSum = windowSum;

        for(int i=windowSize;i<n;i++){
            windowSum += cardPoints[i];
            windowSum -= cardPoints[i-windowSize];
            minWindowSum = min(minWindowSum, windowSum);
        }

        return totalSum - minWindowSum;


    }
};



// 3 case bnega - 
//1 - minWindowSum nikal lenge  uske baad minus krege totalsum se
//2- saara card agar same hai toh khi se bhi lenge k ki value according same ayega
//3 - agar k.length == cardpoints.elngth = total sum

