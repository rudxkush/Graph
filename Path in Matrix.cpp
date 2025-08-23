vector<vector<int>> directions = {
    {1, 0},   // down
    {-1, 0},  // up
    {0, 1},   // right
    {0, -1}   // left
};
int n = 0, m = 0;
bool dfs(vector<vector<int>>& A, int i, int j) {
   if(A[i][j] == 2) return true;
   
   A[i][j] = 0;
   for(auto dir : directions) {
       int x = i + dir[0];
       int y = j + dir[1];
       
       if(x < 0 || y < 0 || x >= n || y >= m) continue;
       if (A[x][y] == 3 || A[x][y] == 2) { 
            if (dfs(A, x, y)) return true;  
        }
   } 
   
   return false;   
}

int Solution::checkPath(vector<vector<int>>& A) {
    n = A.size();
    m = A[0].size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(A[i][j] == 1) if(dfs(A, i, j)) return 1;
        }
    }
    return 0;
}
