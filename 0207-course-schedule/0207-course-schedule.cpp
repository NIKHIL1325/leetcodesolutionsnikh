class Solution {
public:
    bool canFinish(int nu, vector<vector<int>>& to) {
        // 1. Use standard vector<vector<int>> instead of VLA
        vector<vector<int>> adj(nu);
        // 2. Initialize a single vector of size 'nu' with 0s
        vector<int> indegree(nu, 0);

        // Build adjacency list and calculate in-degrees together
        for (auto& it : to) {
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++; // 3. Increment in-degree of the destination node
        }

        // 4. Push ALL nodes with in-degree 0 into the queue
        queue<int> q;
        for (int i = 0; i < nu; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            // 5. Traverse neighbors using 'adj', not 'to'
            for (auto neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return count == nu;
    }
};
