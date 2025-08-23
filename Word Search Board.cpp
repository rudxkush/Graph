#include <vector>
#include <string>
using namespace std;

int n, m;
vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

bool dfs(int row, int col, vector<string> &A, string &B, int i) {
    if(i == B.length()) {
        return true;
    }
    
    for(auto dir : directions) {
        int nr = row + dir[0];
        int nc = col + dir[1];
        if(nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
        if(A[nr][nc] == B[i]) 
            if(dfs(nr, nc, A, B, i + 1)) return true;
    }
    return false;
}

int Solution::exist(vector<string> &A, string B) {
    n = A.size();
    m = A[0].length();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] == B[0]) {
                if (dfs(i, j, A, B, 1)) return 1;
            }
        }
    }
    return 0;
}
