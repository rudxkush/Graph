#include <bits/stdc++.h>
using namespace std;
/*
Given a square chessboard of size (n x n), the initial position and 
target postion of Knight are given.
Find out the minimum steps a Knight will take to reach the target position.
Input: n = 3, knightPos[] = [3, 3], targetPos[]= [1, 2]
Output: 1
Explanation: Knight takes 1 step to reach from (3, 3) to (1 ,2).
O O O O O O O O
O O X O X O O O
O X O O O X O O
O O O K O O O O
O X O O O X O O
O O X O X O O O
O O O O O O O O
O O O O O O O O
*/
class chessBoard {
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

int main() 
{
    chessBoard chess;
    int n = 3; 
    vector<int> knightPos = {3, 3}, targetPos = {1, 2};
    cout << chess.minStepToReachTarget(knightPos, targetPos, n) << endl;
    return 0;
}
