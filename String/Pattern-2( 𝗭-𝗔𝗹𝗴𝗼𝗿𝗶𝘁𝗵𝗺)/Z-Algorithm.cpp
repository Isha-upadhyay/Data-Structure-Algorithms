#include <bits/stdc++.h>
using namespace std;

// --- Z-Algorithm function ---
// Z[i] = length of longest substring starting at i
// which is also a prefix of the string.
vector<int> computeZArray(const string &s) {
    int n = (int)s.size();
    vector<int> Z(n, 0);

    int L = 0, R = 0; // current [L,R] window that matches prefix
    for (int i = 1; i < n; i++) {
        // If i is within the current [L,R] window
        if (i <= R) {
            int k = i - L;
            // We can safely take the minimum of previously computed value and remaining length of window
            Z[i] = min(Z[k], R - i + 1);
        }
        // Try to extend the match beyond current window
        while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]]) {
            Z[i]++;
        }
        // If extended beyond R, update L and R
        if (i + Z[i] - 1 > R) {
            L = i;
            R = i + Z[i] - 1;
        }
    }
    return Z;
}

int main() {
    // Input: first Text, then Pattern
    string text, pattern;
    cout << "Enter text: ";
    cin >> text;
    cout << "Enter pattern: ";
    cin >> pattern;

    // Combine pattern + special character + text
    string combined = pattern + '#' + text;

    // Compute Z array for combined string
    vector<int> Z = computeZArray(combined);

    // Count occurrences of pattern in text
    int countMatches = 0;
    for (int val : Z) {
        if (val == (int)pattern.size()) {
            countMatches++;
        }
    }

    cout << "Pattern occurs " << countMatches << " time(s) in text.\n";
    return 0;
}
