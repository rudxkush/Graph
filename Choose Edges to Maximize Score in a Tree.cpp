int rec(vector<vector<pair<int,int>>>& tree, int node, int parent, bool pickParentEdge) {
    long long sum = 0;

    for (auto [nei, wt] : tree[node]) {
        if (nei == parent) continue;
      
        if (pickParentEdge) {
            // Previously picked! 
            // Gonna skip the choices option for this
            sum += rec(tree, nei, node, false);
        } else {
            // Option1: skip node→nei
            int skip = rec(tree, nei, node, false);

            // Option2: take node→nei
            int take = wt + rec(tree, nei, node, true);

            sum += max(skip, take);
        }
    }

    return sum;
}

int maxNonAdjacentSum(vector<vector<int>>& edges) {
    int n = edges.size();
    vector<vector<pair<int,int>>> tree(n);

    for (int i = 0; i < n; i++) {
        if (edges[i][0] != -1) {
            tree[i].push_back({edges[i][0], edges[i][1]});
            tree[edges[i][0]].push_back({i, edges[i][1]});
        }
    }
    return rec(tree, 0, -1, false);
}

