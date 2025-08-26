class Solution {
  public:
    vector<vector<int>> moves = {{-2, -1}, {-1, -2}, {-1, 2}, {-2, 1}, {2, 1}, {1, 2}, {1, -2}, {2, -1}};
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
      queue<pair<pair<int, int>, int>> q;
      q.push({{knightPos[0] - 1, knightPos[1] - 1}, 0});
      vector<vector<int>> visited(n, vector<int>(n, false));
      visited[knightPos[0] - 1][knightPos[1] - 1] = true;
      
      while(!q.empty()) {
        int rank = q.front().first.first; 
        int file = q.front().first.second;
        int steps = q.front().second;
        q.pop();
        
        if(rank == (targetPos[0] - 1) && file == (targetPos[1] - 1)) return steps;
        
        for(auto move : moves) {
          int newRank = rank + move[0];
          int newFile = file + move[1];
          if(newRank >= n || newFile >= n || newRank < 0 || newFile < 0 || visited[newRank][newFile]) continue;
          
          q.push({{newRank, newFile}, steps + 1});
          visited[newRank][newFile] = true;
        }
      }
      return -1;
    }
};
