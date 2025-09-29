class DisjointSet {
    vector<int> rank, parent;
public:
    // Initializes disjoint sets
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    // path compression
    int findUltimateParent(int node) {
        if(node == parent[node])
            return node;
        return parent[node] = findUltimateParent(parent[node]);
    }
    
    void unionByRank(int u, int v) {
        int ultimateParent_u = findUltimateParent(u);
        int ultimateParent_v = findUltimateParent(v);

        if(ultimateParent_u == ultimateParent_v) return;
      
        if(rank[ultimateParent_u] < rank[ultimateParent_v]) {
            parent[ultimateParent_u] = ultimateParent_v;
        } else if(rank[ultimateParent_u] > rank[ultimateParent_v]) {
            parent[ultimateParent_v] = ultimateParent_u;
        } else { 
            parent[ultimateParent_v] = ultimateParent_u;
            rank[ultimateParent_u]++;
        }
    }
};

int Solution::breakRecords(int A, vector<vector<int>> &B) {
    DisjointSet obj(A);
    
    for(auto &it : B) 
        obj.unionByRank(it[0], it[1]);
        
    int count = 0;
    for(int i = 1; i <= A; i++) {
        if(obj.findUltimateParent(i) == i) count++;
    }
    return count;
}
