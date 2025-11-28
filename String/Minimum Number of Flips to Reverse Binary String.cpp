class Solution {
public:
    int minimumFlips(int n) {
        
       string s = "";
        
        // convert to binary
        while(n > 0){
            s += (n % 2) + '0';
            n /= 2;
        }
        reverse(s.begin(), s.end());
        
        int flips = 0;
        int L = s.length();
        
        for(int i = 0; i < L/2; i++){
            if(s[i] != s[L - 1 - i]){
                flips += 2;  // both ends need flipping
            }
        }
        
        return flips;


        
    }
};


// n 
// s -> binary re
// 
