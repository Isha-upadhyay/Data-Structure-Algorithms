class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int mod = 1e9 + 7;

        deque<pair<int, int>> know, share;

        know.emplace_back(1, 1); // one person knows the secret

        int know_cnt = 1;
        int share_cnt = 0;

        // here move people from know to share after their delay ends
        for (int day = 2; day <= n; day++) {
            if (!know.empty() && know.front().first == day - delay) {
                int x = know.front().second;
                know_cnt = (know_cnt - x + mod) % mod;
                share_cnt = (share_cnt + x) % mod;
                share.push_back(know.front());
                know.pop_front();
            }

            // remove people from share when they forget the secret
            if (!share.empty() && share.front().first == day - forget) {
                int y = share.front().second;
                share_cnt = (share_cnt - y + mod) % mod;
                share.pop_front();
            }

            // now new current sharers are tell to other new people
            if (!share.empty()) {
                know_cnt = (know_cnt + share_cnt) % mod;
                know.emplace_back(day, share_cnt);
            }
        }

        return (know_cnt + share_cnt) % mod;
    }
};
