vector<vector<int>> directions = {
    {1,0}, {-1,0}, {0,1}, {0,-1},   // 4 directions
    {1,1}, {1,-1}, {-1,1}, {-1,-1} // diagonals
};

bool canReach(vector<vector<int>>& rect, int i, int j, int A, int B) {
    if(i < 0 || j < 0 || i > A || j > B) return false;  // out of bounds
    if(rect[i][j] == 1) return false;                   // blocked or visited
    if(i == A && j == B) return true;                   // reached end
    
    rect[i][j] = 1; // mark visited
    
    for(auto &dir : directions) {
        if(canReach(rect, i + dir[0], j + dir[1], A, B)) return true;
    }
    return false;
}

string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    vector<vector<int>> rect(A + 1, vector<int>(B + 1, 0));

    // Mark cells inside or on any circle as blocked
    for(int i = 0; i <= A; i++) {
        for(int j = 0; j <= B; j++) {
            for(int k = 0; k < C; k++) {
                int dx = i - E[k];
                int dy = j - F[k];
                if(dx*dx + dy*dy <= D*D) {
                    rect[i][j] = 1;
                    break;
                }
            }
        }
    }

    // If start or end is blocked
    if(rect[0][0] == 1 || rect[A][B] == 1) return "NO";

    // DFS to check if path exists
    return canReach(rect, 0, 0, A, B) ? "YES" : "NO";
}
