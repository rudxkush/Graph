#include <bits/stdc++.h>
using namespace std;
/*
Input: edges = [[0,1,7],[1,4,5],[0,2,6],[2,3,6],[3,4,2],[2,4,6]], 
       online = [true,true,true,false,true], k = 12
Output: 6
Node 3 is offline, so any path passing through 3 is invalid.
Consider the remaining routes from 0 to 4. Path : 0 → 1 → 4
Total cost = 7 + 5 = 12 <= k, so this path is valid.
The minimum edge‐cost along this path is min(7, 5) = 5. Path : 0 → 2 → 3 → 4
Node 3 is offline, so this path is invalid regardless of cost. Path : 0 → 2 → 4
Total cost = 6 + 6 = 12 <= k, so this path is valid.
The minimum edge‐cost along this path is min(6, 6) = 6.
Among the two valid paths, their scores are 5 and 6. Therefore, the answer is 6.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ans = -1;

    void dfs(vector<vector<pair<int, int>>>& graph, int node, int dest, long long k, 
             long long sum, int minEdgeCost, vector<bool>& visited) {
        if (sum > k) return;
        if (node == dest) {
            ans = max(ans, minEdgeCost);
            return;
        }

        visited[node] = true;

        for (auto& [neighbor, cost] : graph[node]) {
            if (!visited[neighbor]) {
                dfs(graph, neighbor, dest, k, sum + cost, min(minEdgeCost, cost), visited);
            }
        }

        visited[node] = false;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> graph(n);

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], cost = edge[2];
            if (online[u] && online[v]) {
                graph[u].emplace_back(v, cost);
            }
        }

        vector<bool> visited(n, false);
        dfs(graph, 0, n - 1, k, 0, INT_MAX, visited);

        return ans;
    }
};

int main() {
    Solution obj;
    vector<vector<int>> edges = {{0,1,7},{1,4,5},{0,2,6},{2,3,6},{3,4,2},{2,4,6}};
    vector<bool> online = {true,true,true,false,true};
    int k = 12;
    cout << obj.findMaxPathScore(edges, online, k) << endl;
    return 0;
}
