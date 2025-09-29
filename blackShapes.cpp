vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int n = 0, m = 0;
void dfs(vector<string>& A, int row, int col) {
  A[row][col] = 'O';
  
  for(auto dir : directions) {
    int x = dir[0];
    int y = dir[1];
    int nrow = row + x;
    int ncol = col + y;
    // validate the cell
    if(nrow < 0 || ncol < 0 || nrow >= n || ncol >= m || A[nrow][ncol] == 'O') continue;
    // dfs call!
    dfs(A, nrow, ncol);
  }
}

int Solution::black(vector<string>& A) {
  n = A.size(), m = A[0].size(); 
  int count = 0;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      if(A[i][j] == 'X') {
        count++;
        dfs(A, i, j);
      }
    }
  }
  return count;
}
