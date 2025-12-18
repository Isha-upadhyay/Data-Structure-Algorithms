//sliding window

class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();

        // 1. Base (original) profit without any modification
        long long actualP = 0;
        vector<long long> profit(n);

        for (int i = 0; i < n; i++) {
            profit[i] = 1LL * strategy[i] * prices[i];
            actualP += profit[i];
        }

        // 2. Sliding window variables
        long long originalWindProfit = 0;   // old profit inside window
        long long modifiedWindProfit = 0;   // new profit (0...0,1...1)
        long long maxGain = 0;

        int i = 0;  // left pointer

        // 3. Sliding window
        for (int j = 0; j < n; j++) {
            // add right element to original window profit
            originalWindProfit += profit[j];

            // second half of window => SELL (1)
            if (j - i + 1 > k / 2) {
                modifiedWindProfit += prices[j];
            }

            // shrink window if size > k
            if (j - i + 1 > k) {
                originalWindProfit -= profit[i];
                modifiedWindProfit -= prices[i + k / 2];
                i++;
            }

            // evaluate window of exact size k
            if (j - i + 1 == k) {
                maxGain = max(maxGain, modifiedWindProfit - originalWindProfit);
            }
        }

        // 4. Final answer
        return actualP + maxGain;
    }
};


// prefix sum


class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        long long baseProfit = 0;

        for (int i = 0; i < n; i++) {
            baseProfit += 1LL * strategy[i] * prices[i];
        }

        vector<long long> deltaHold(n), deltaSell(n);

        for (int i = 0; i < n; i++) {
            long long old = 1LL * strategy[i] * prices[i];
            deltaHold[i] = -old;
            deltaSell[i] = prices[i] - old;
        }

        vector<long long> prefHold(n + 1, 0), prefSell(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefHold[i + 1] = prefHold[i] + deltaHold[i];
            prefSell[i + 1] = prefSell[i] + deltaSell[i];
        }

        long long maxGain = 0;
        int half = k / 2;

        for (int l = 0; l + k <= n; l++) {
            long long holdGain = prefHold[l + half] - prefHold[l];
            long long sellGain = prefSell[l + k] - prefSell[l + half];
            maxGain = max(maxGain, holdGain + sellGain);
        }

        return baseProfit + maxGain;
    }
};
