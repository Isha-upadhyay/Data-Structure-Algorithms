class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> row_mask;
        for(auto& r: reservedSeats){
            row_mask[r[0]] |= (1 << r[1]); // seat k -> bit k
        }

        int ans = 0;
        long long empty = n - (long long)row_mask.size(); // if there is any row empty
        ans += empty * 2; // empty row = + 2 groups


        for(auto& [_, mask] : row_mask){ // check reserved row mask
            
            // block A seats 2-5
            bool A = (mask & ((1 << 2) | (1 << 3) |(1 << 4)|(1<<5))) == 0;

            // block B seats 6-9
            bool B = (mask & ((1 << 6) | (1 << 7) | (1 << 8) | (1 << 9))) == 0;

            // block C seats 4-7
            bool C = (mask & ((1 << 4) | (1 << 5) | (1 << 6) | (1 << 7))) == 0;

            if(A && B){
                ans +=2;
            }else if(A  || B || C){
                ans += 1;
            }
        }
        return ans;
    }
};
