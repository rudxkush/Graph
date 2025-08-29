class DisjointSet {
    vector<int> parent, size;
public:
    // Initializes disjoint sets
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // Path compression
    int findUltimateParent(int node) {
        if(node == parent[node])
            return node;
        return parent[node] = findUltimateParent(parent[node]);
    }
    
    void unionBySize(int u, int v) {
        int ultimateParent_u = findUltimateParent(u);
        int ultimateParent_v = findUltimateParent(v);
      
        if(ultimateParent_u == ultimateParent_v) return;
      
        if(size[ultimateParent_u] < size[ultimateParent_v]) {
            parent[ultimateParent_u] = ultimateParent_v; 
            size[ultimateParent_v] += size[ultimateParent_u];
        } else {
            parent[ultimateParent_v] = ultimateParent_u; 
            size[ultimateParent_u] += size[ultimateParent_v];
        }
    }
};

int Solution::solve(vector<int> &A, vector<int> &B, vector<vector<int>> &C) {
    int n = A.size();
    DisjointSet ds(n);
    for(auto &it : C)
        ds.unionBySize(it[0]-1, it[1]-1);

    // Map value → index in B
    unordered_map<int,int> valueToIndexB;
    for(int i = 0; i < n; i++) valueToIndexB[B[i]] = i;

    // Check if each value in A can move to its place in B
    for(int i = 0; i < n; i++) {
        if(A[i] != B[i]) {
            int idxA = i;
            int idxB = valueToIndexB[A[i]];
            if(ds.findUltimateParent(idxA) != ds.findUltimateParent(idxB))
                return 0;
        }
    }

    return 1;
}
