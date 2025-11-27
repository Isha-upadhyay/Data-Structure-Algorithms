class Solution {
public:
    int reverse(int x) {
        int reversedNumber = 0; 
    while (x != 0) {
        int lastDigit = x % 10; 

        
        if (reversedNumber > INT_MAX / 10 || (reversedNumber == INT_MAX / 10 && lastDigit > 7)) {
            return 0; 
        }
        if (reversedNumber < INT_MIN / 10 || (reversedNumber == INT_MIN / 10 && lastDigit < -8)) {
            return 0; 
        }

        reversedNumber = reversedNumber * 10 + lastDigit; // Update reversedNumber with last digit
        x /= 10; 
    }
    return reversedNumber; 
    }
};
