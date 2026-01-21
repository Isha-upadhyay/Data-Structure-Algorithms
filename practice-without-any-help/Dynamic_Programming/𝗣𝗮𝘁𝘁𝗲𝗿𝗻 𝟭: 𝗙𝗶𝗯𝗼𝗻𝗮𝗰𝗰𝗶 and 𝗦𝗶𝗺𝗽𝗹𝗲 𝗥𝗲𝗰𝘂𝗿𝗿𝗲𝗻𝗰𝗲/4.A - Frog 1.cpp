#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> h(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> h[i];
    }

    // Edge case: only one jump
    if (N == 2) {
        cout << abs(h[2] - h[1]) << endl;
        return 0;
    }

    int prev2 = 0;                        // dp[1]
    int prev1 = abs(h[2] - h[1]);         // dp[2]

    for (int i = 3; i <= N; i++) {
        int curr = min(
            prev1 + abs(h[i] - h[i - 1]),
            prev2 + abs(h[i] - h[i - 2])
        );
        prev2 = prev1;
        prev1 = curr;
    }

    cout << prev1 << endl;
    return 0;
}
