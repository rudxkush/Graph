#include <bits/stdc++.h>
using namespace std;

int canReach(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int,int>>> graph(n);
    for (auto &f : flights) {
        graph[f[0]].push_back({f[1], f[2]});
    }

    // {city, cost, stops}
    queue<tuple<int,int,int>> q;
    q.push({src, 0, 0});

    vector<int> minCost(n, INT_MAX);
    minCost[src] = 0;

    int ans = INT_MAX;

    while (!q.empty()) {
        auto [city, cost, stops] = q.front();
        q.pop();

        if (city == dst) {
            ans = min(ans, cost);
            continue;
        }

        if (stops > k) continue;

        for (auto &[nei, price] : graph[city]) {
            int newCost = cost + price;
            if (newCost < minCost[nei] && cost <= ans) { 
                minCost[nei] = newCost;
                q.push({nei, newCost, stops+1});
            }
        }
    }

    return (ans == INT_MAX ? -1 : ans);
}

int main() {
    int n = 3;
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{0,2,500}};
    int src = 0, dst = 2, k = 1;
    cout << canReach(n, flights, src, dst, k) << endl;  // Output: 200
    return 0;
}
