#include <bits/stdc++.h>
using namespace std;

int minSpanningTreePrims(vector<vector<pair<int, int>>>& adj, int n) {
  priority_queue<pair<int, int>,
                 vector<pair<int, int>>,
                 greater<pair<int, int>>> q; // {Weight, Destination}
                 
  vector<int> visited(n, false);
  q.push({0, 0});
  int mstSum = 0;
  while(!q.empty()) {
    auto [wt, u] = q.top();
    q.pop();
    if(visited[u]) continue;
    visited[u] = true;
    mstSum += wt;
    
    for(auto& [v, w] : adj[u]) {
      if(!visited[v]) {
        q.push({w, v});
      }
    }
  }
  return mstSum;
}

int minCostConnectPoints(vector<vector<int>>& points) {
  int n = points.size();
  vector<vector<pair<int, int>>> adj(n);
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      int manhattanDist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
      adj[i].push_back({j, manhattanDist});
      adj[j].push_back({i, manhattanDist});
    }
  }
  return minSpanningTreePrims(adj, n);
  // return minSpanningTreeKruskal(adj, n);
}

int main() 
{
    vector<vector<int>> points = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    cout << minCostConnectPoints(points) << endl;
    return 0;
}
