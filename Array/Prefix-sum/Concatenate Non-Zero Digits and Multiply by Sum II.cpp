class Solution {
public:
     using ll = long long;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        ll n = s.length(), m = queries.size();
        const ll MOD = 1e9 + 7;

        vector<ll> pre(n), count(n), sum(n);
        vector<ll> pow10(n+1);
        pow10[0] = 1;


        for(int i=1;i<=n;++i){
            pow10[i] = (pow10[i-1] * 10) % MOD; // n = 5, pow10 = [1, 10, 100, 1000, 10000, 100000]
        }


        for(int i=0;i<n;i++){
            int dig = s[i] - '0'; // s[i] = '3 -> dig = 3

            if(i){ 
                pre[i] = pre[i-1];
                sum[i] = sum[i-1];
                count[i] = count[i-1];
            }


            if(dig != 0){ 
                pre[i] = (pre[i] * 10 + dig) % MOD;
                sum[i] += dig;
                count[i] += 1;
            }
        }


        vector<int> res(m);
        int qi = 0;

        for(auto &query : queries){
            int l = query[0];
            int r = query[1];


            ll cnt = count[r] - (l ? count[l-1] : 0);

            if(cnt == 0){
                res[qi++] = 0;
                continue;
            }

            ll dig_sum = sum[r] - (l ? sum[l-1] : 0);

            ll left_pre = (l ? pre[l-1] : 0);

            ll x = (pre[r] - (left_pre * pow10[cnt]) % MOD) % MOD;

            if(x < 0) x += MOD;

            res[qi++] = (x*dig_sum) % MOD;
        }

        return res;

    }
};
