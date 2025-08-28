int Solution::solve(int n, vector<vector<int> > &B, int C, int D, vector<vector<int> > &E) {
    vector<vector<int>> distance(n+1, vector<int>(2, 1e9));
    distance[C][0] = 0;
    distance[C][1] = 0;
   
    vector<vector<pair<int,int>>> graph(n+1);
    vector<vector<pair<int,int>>> extraGraph(n+1);
   
    for(auto &edge: B) {
        graph[edge[0]].push_back({edge[1],edge[2]});
        graph[edge[1]].push_back({edge[0],edge[2]});
    }
   
    for(auto &edge: E) {
        extraGraph[edge[0]].push_back({edge[1],edge[2]});
        extraGraph[edge[1]].push_back({edge[0],edge[2]});
    }
   
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pQ;
    pQ.push({0, {C, 0}});
    while(!pQ.empty()){
        auto [dis, tp] = pQ.top(); pQ.pop();
        auto [node, extraFlag] = tp;
       
        for(auto [nei, wt]: graph[node]) {
            if(dis + wt < distance[nei][extraFlag]) {
                distance[nei][extraFlag] = dis + wt;
                pQ.push({dis + wt, {nei, extraFlag}});
            }
        }
        
        if(extraFlag == 0) {
            for(auto [nei, wt] : extraGraph[node]) {
                if(dis + wt < distance[nei][1]) {
                    distance[nei][1] = dis + wt;
                    pQ.push({dis + wt, {nei, 1}});
                }
            }
        }
    }
    if(distance[D][0] == 1e9 && distance[D][1] == 1e9) return -1;
    
    return min(distance[D][0], distance[D][1]);
}

