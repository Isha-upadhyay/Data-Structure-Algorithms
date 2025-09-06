#include <bits/stdc++.h>
using namespace std;

// Namespace to handle string utility functions
namespace str {

    /**
     * Computes the prefix function (pi array) for string s.
     * pi[i] stores the length of the longest proper prefix of s[0..i]
     * which is also a suffix of s[0..i].
     */
    vector<int> pi(const string &s) {
        int n = (int)s.size();
        vector<int> pi_s(n);  // Initialize pi array with zeros

        // Build the pi array
        for (int i = 1, j = 0; i < n; i++) {
            // If there is a mismatch, we jump back in the pattern using pi array
            while (j > 0 && s[i] != s[j]) {
                j = pi_s[j - 1];
            }

            // If characters match, increment the length of current prefix
            if (s[i] == s[j]) {
                j++;
            }

            // Store the length of the longest prefix-suffix for position i
            pi_s[i] = j;
        }

        return pi_s;
    }
}  // namespace str

int main() {
    string T, P;
    
    // Input: First the text T, then the pattern P
    cin >> T >> P;

    // Combine pattern, a delimiter, and text for KMP processing
    string S = P + '#' + T;

    // Compute pi array for the concatenated string
    vector<int> pi = str::pi(S);

    int ans = 0;

    // Count how many times the full pattern P occurs in text T
    for (int l : pi) {
        if (l == P.size()) {
            ans++;
        }
    }

    // Output the number of occurrences of pattern P in text T
    cout << ans << '\n';

    return 0;
}
