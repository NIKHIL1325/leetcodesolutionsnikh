#include <vector>
using namespace std;

class Solution {
private:
    bool hasCycle(int node, vector<vector<int>>& adj, vector<int>& state) {
        state[node] = 1; // Mark as currently visiting (in recursion stack)
        
        for (int neighbor : adj[node]) {
            if (state[neighbor] == 1) {
                return true; // Back-edge found -> cycle exists
            }
            if (state[neighbor] == 0) {
                if (hasCycle(neighbor, adj, state)) {
                    return true;
                }
            }
        }
        
        state[node] = 2; // Mark as completely visited
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (const auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]); // prereq -> course
        }
        
        vector<int> state(numCourses, 0);
        
        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0) {
                if (hasCycle(i, adj, state)) {
                    return false; // Cycle found, cannot finish courses
                }
            }
        }
        
        return true;
    }
};
