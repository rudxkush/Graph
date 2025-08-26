vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};  
vector<char> distancesChar = {'R', 'D', 'L', 'U'};


int Solution::solve(int A, int B, vector<string> &C) {
    deque<pair<pair<int, int>, int>> q;
    vector<vector<int>> distance(A, vector<int>(B, INT_MAX));
    
    q.push_front({{0, 0}, 0});
    while(!q.empty()) {
        auto [pos, cost] = q.front(); q.pop_front();
        int x = pos.first, y = pos.second;
        
        if(x == A - 1 && y == B - 1) return cost;
        
        for(int k = 0; k < 4; k++) {
            int nx = x + dirs[k][0]; 
            int ny = y + dirs[k][1];
            
            // validate movement
            if(nx < 0 || ny < 0 || nx >= A || ny >= B) continue;
            // calculate the cost that we might incur 
            int temp = (C[x][y] == distancesChar[k]) ? 0 : 1;
            
            if(cost + temp < distance[nx][ny]) {
                distance[nx][ny] = cost + temp;
                if(temp == 0)
                    q.push_front({{nx, ny}, cost});
                else
                    q.push_back({{nx, ny}, cost + 1});
            }
        }
    }
    return -1;
}
