vector<vector<string> > Solution::findLadders(string start, string end, vector<string> &dict) {
    vector<vector<string>> result;
    unordered_set<string> st;
    st.insert(end);
    for(auto it: dict) st.insert(it);
    
    queue<vector<string>> q;
    q.push({start});
    
    while(!q.empty()){
        vector<string> a = q.front();
        q.pop();
        if(a.back() == end)result.push_back(a);
        string s = a.back();
        st.erase(s);
        
        int n = s.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 26; j++){
                string c = s;
                c[i] = ('a' + j);
                if(st.find(c) != st.end()){
                    vector<string> temp = a;
                    temp.push_back(c);
                    q.push(temp);
                }
            }
        }
    }
    return result;
}
