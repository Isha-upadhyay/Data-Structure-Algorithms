#include <bits/stdc++.h>
using namespace std;

vector<int> rabinKarp(const string &text, const string &pattern) {
    int n = text.size();
    int m = pattern.size();

    if (m > n) return {}; // agar pattern bada hai text se

    int d = 256; // alphabet size
    int q = 101; // prime number for modulo
    int h = 1;

    // precompute h = pow(d, m-1) % q
    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    int p_hash = 0; // pattern ka hash
    int t_hash = 0; // text window ka hash

    // initial hash compute karo
    for (int i = 0; i < m; i++) {
        p_hash = (d * p_hash + pattern[i]) % q;
        t_hash = (d * t_hash + text[i]) % q;
    }

    vector<int> result;

    // slide window
    for (int i = 0; i <= n - m; i++) {
        // hash compare
        if (p_hash == t_hash) {
            // collision check
            if (text.substr(i, m) == pattern) {
                result.push_back(i);
            }
        }

        // next window hash compute karo
        if (i < n - m) {
            t_hash = (d * (t_hash - text[i] * h) + text[i + m]) % q;

            // negative hash ko positive karo
            if (t_hash < 0)
                t_hash += q;
        }
    }

    return result;
}

int main() {
    string text, pattern;
    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter pattern: ";
    getline(cin, pattern);

    vector<int> matches = rabinKarp(text, pattern);

    if (matches.empty()) {
        cout << "Pattern not found in text.\n";
    } else {
        cout << "Pattern found at indices: ";
        for (int idx : matches) cout << idx << " ";
        cout << endl;
    }

    return 0;
}
