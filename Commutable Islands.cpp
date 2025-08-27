int Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<pair<int, int>>> graph(A);
    for(auto edge : B) {
        int u = edge[0] - 1; // conversion to 0 indexed.
        int v = edge[1] - 1; // conversion to 0 indexed.
        int wt = edge[2];
        graph[u].push_back({v, wt});
        graph[v].push_back({u, wt});
    }
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> minHeap; // to get the one that has the least cost.
                   
    minHeap.push({0, 0}); // {cost, node} so minHeap is created on cost.
    vector<bool> visited(A, false);
    int ans = 0;
    while(!minHeap.empty()) {
        auto [cost, node] = minHeap.top(); minHeap.pop();
        if(visited[node] == true) continue;
        visited[node] = true;
        // cout << node << ", " << cost << endl;
        ans += cost;
        
        for(auto [nei, neiCost] : graph[node]) {
            if(!visited[nei]) {
                minHeap.push({neiCost, nei});
            }
        }
    }
    return ans;
}


