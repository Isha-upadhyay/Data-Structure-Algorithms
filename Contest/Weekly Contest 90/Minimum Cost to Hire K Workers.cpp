class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();

        vector<pair<double, int>> workers;

        for(int i=0;i<n;i++){
            double ratio = (double)wage[i] / quality[i];
            workers.push_back({ratio, quality[i]});
        }

        // sort
        sort(workers.begin(), workers.end());

        priority_queue<int> pq;
        int qualitySum = 0;
        double ans = 1e18;

        for(auto &w : workers){
            double ratio = w.first;
            int q = w.second;
            pq.push(q);
            qualitySum += q;


            if(pq.size() > k){
                qualitySum -= pq.top();
                pq.pop();
            }
            if(pq.size() == k){
                ans = min(ans, ratio * qualitySum);
            }
        }
        return ans;

    }
};


//  n 
// quality - quality[i] 
// wage - wage[i] - minwage
// k - worker hire
// ratio = 70/10 = 7
// 50/20 = 2.5 
// 30/5 = 6
// ratio = max(7, 6) = 7
// sum = 7 + 6 = 15
//15 * 7 = 105
// pay = ratio * quality
// 7 * 10 = 0
//7 * 5 = 35

