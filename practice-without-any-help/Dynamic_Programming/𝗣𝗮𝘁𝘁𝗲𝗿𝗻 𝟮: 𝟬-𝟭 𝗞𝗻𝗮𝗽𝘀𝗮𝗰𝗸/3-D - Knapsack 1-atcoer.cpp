#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, W;
    cin >> N >> W;

    vector<long long> dp(W + 1, 0);

    for (int i = 0; i < N; i++) {
        int weight;
        long long value;
        cin >> weight >> value;

        // 0/1 Knapsack (reverse loop)
        for (int w = W; w >= weight; w--) {
            dp[w] = max(dp[w], dp[w - weight] + value);
        }
    }

    cout << dp[W] << endl;
    return 0;
}
