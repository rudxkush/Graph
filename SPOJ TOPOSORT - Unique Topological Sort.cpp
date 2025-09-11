#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<vector<int>> graph(n + 1);
        vector<int> indegree(n + 1, 0);

        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y);
            indegree[y]++;
        }

        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) pq.push(i);
        }

        vector<int> result;
        while (!pq.empty()) {
            int node = pq.top();
            pq.pop();
            result.push_back(node);

            for (int nei : graph[node]) {
                indegree[nei]--;
                if (indegree[nei] == 0) pq.push(nei);
            }
        }

        if ((int)result.size() != n) {
            cout << "Sandro fails.\n";
        } else {
            for (int i = 0; i < n; i++) {
                cout << result[i] << (i + 1 == n ? '\n' : ' ');
            }
        }
    }
    return 0;
}
