#define ll long long

class Solution {
public:
    // GCD
    int gcd(int a, int b){
        if (!b) return a;
        return gcd(b, a % b);
    }

    // LCM
    int lcm(ll a, ll b){
        ll temp = (a / gcd(a, b)) * b;
        return temp > INT_MAX ? INT_MAX : temp; // Avoid overflow
    }

    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {

        int l = 1, r = INT_MAX;
        int LCM = lcm(divisor1, divisor2);

        while (l <= r) {
            int mid = l + (r - l) / 2;

            // Count numbers divisible by divisor1 and divisor2
            int a = mid / divisor1;
            int b = mid / divisor2;

            // Condition check
            if (uniqueCnt1 <= mid - a && uniqueCnt2 <= mid - b && uniqueCnt1 + uniqueCnt2 <= (mid - (mid / LCM))) {
                r = mid - 1; // Try smaller
            } else {
                l = mid + 1; // Increase mid
            }
        }
        return l;
    }
};
