class Solution {
private:
    int cycleStart = -1;

    // Peform the DFS and store a node in the cycle as cycleStart.
    void DFS(int src, vector<bool> &visited, vector<int> adjList[],
             vector<int> &parent) {
        visited[src] = true;

        for (int adj : adjList[src]) {
            if (!visited[adj]) {
                parent[adj] = src;
                DFS(adj, visited, adjList, parent);
                // If the node is visited and the parent is different then the
                // node is part of the cycle.
            } else if (adj != parent[src] && cycleStart == -1) {
                cycleStart = adj;
                parent[adj] = src;
            }
        }
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        int N = edges.size();

        vector<bool> visited(N, false);
        vector<int> parent(N, -1);

        vector<int> adjList[N];
        for (auto edge : edges) {
            adjList[edge[0] - 1].push_back(edge[1] - 1);
            adjList[edge[1] - 1].push_back(edge[0] - 1);
        }

        DFS(0, visited, adjList, parent);

        unordered_map<int, int> cycleNodes;
        int node = cycleStart;
        // Start from the cycleStart node and backtrack to get all the nodes in
        // the cycle. Mark them all in the map.
        do {
            cycleNodes[node] = 1;
            node = parent[node];
        } while (node != cycleStart);

        // If both nodes of the edge were marked as cycle nodes then this edge
        // can be removed.
        for (int i = edges.size() - 1; i >= 0; i--) {
            if (cycleNodes[edges[i][0] - 1] && cycleNodes[edges[i][1] - 1]) {
                return edges[i];
            }
        }

        return {};
    }
};
