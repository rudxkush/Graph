int Solution::solve(vector<int> &A, vector<int> &B, vector<vector<int>> &C) {
    int n = A.size();
    if (n != (int)B.size()) return 0;

    // Build graph of indices
    vector<vector<int>> graph(n);
    for (auto &pair : C) {
        int u = pair[0] - 1; // convert to 0-index
        int v = pair[1] - 1;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> visited(n, 0);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            // BFS to collect the connected component
            queue<int> q;
            q.push(i);
            visited[i] = 1;

            vector<int> compIndices;
            while (!q.empty()) {
                int node = q.front(); q.pop();
                compIndices.push_back(node);

                for (int nei : graph[node]) {
                    if (!visited[nei]) {
                        visited[nei] = 1;
                        q.push(nei);
                    }
                }
            }

            // Compare values from A and B inside this component
            vector<int> valsA, valsB;
            for (int idx : compIndices) {
                valsA.push_back(A[idx]);
                valsB.push_back(B[idx]);
            }
            sort(valsA.begin(), valsA.end());
            sort(valsB.begin(), valsB.end());

            if (valsA != valsB) return 0;
        }
    }

    return 1;
}
