class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {

        // Step 1: sort meetings by time
        sort(meetings.begin(), meetings.end(),
             [](auto &a, auto &b) {
                 return a[2] < b[2];
             });

        // Step 2: track who knows the secret
        vector<bool> knows(n, false);
        knows[0] = true;
        knows[firstPerson] = true;

        int i = 0;
        int m = meetings.size();

        // Step 3: process meetings time by time
        while (i < m) {
            int currTime = meetings[i][2];

            // temporary graph for current time
            unordered_map<int, vector<int>> graph;
            unordered_set<int> people;

            // collect all meetings at this time
            while (i < m && meetings[i][2] == currTime) {
                int x = meetings[i][0];
                int y = meetings[i][1];
                graph[x].push_back(y);
                graph[y].push_back(x);
                people.insert(x);
                people.insert(y);
                i++;
            }

            // BFS queue
            queue<int> q;
            unordered_set<int> visited;

            // start BFS from people who already know the secret
            for (int p : people) {
                if (knows[p]) {
                    q.push(p);
                    visited.insert(p);
                }
            }

            // BFS inside same time frame
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : graph[u]) {
                    if (!visited.count(v)) {
                        visited.insert(v);
                        q.push(v);
                    }
                }
            }

            // mark all visited as knowing the secret
            for (int p : visited) {
                knows[p] = true;
            }
        }

        // Step 4: collect result
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (knows[i]) result.push_back(i);
        }

        return result;
    }
};
