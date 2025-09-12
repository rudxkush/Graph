
class Solution {
  public:
    vector<int> topologicalSort(vector<vector<int>>& adjList, int k, vector<int>& inDegree) {
        queue<int> q;
        vector<int> topo;
        for(int i = 0; i < k; i++) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }
        int count = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto neighbour : adjList[node]) {
                inDegree[neighbour]--;
                if(inDegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }
        return topo.size() == k ? topo : vector<int>{};
    }
    
    string findOrder(vector<string> &words) {
        if(words.empty()) return "";
        
        vector<bool> present(26, false);
        vector<vector<int>> adjList(26);
        vector<int> inDegree(26, 0);
        
        // Mark the characters that are present in the dictionary
        for(const string& word : words) {
            for(char ch : word) {
                present[ch - 'a'] = true;
            }
        }
        
        for(int i = 0; i < words.size() - 1; i++) {
            string s1 = words[i];
            string s2 = words[i + 1];
            int length = min(s1.length(), s2.length());
            bool found = false;
            
            for(int j = 0; j < length; j++) {
                if(s1[j] != s2[j]) {
                    adjList[s1[j] - 'a'].push_back(s2[j] - 'a');
                    inDegree[s2[j] - 'a']++;
                    found = true;
                    break;
                }
            }
            if(!found && s1.length() > s2.length()) {
                return ""; 
            }
        }
        
        vector<int> topoSort = topologicalSort(adjList, 26, inDegree);
        if(topoSort.empty()) {
            return "";
        }
        
        string res = "";
        for(int i = 0; i < topoSort.size(); i++) {
            if(present[topoSort[i]]) {
                res += (topoSort[i] + 'a');
            }
        }
        
        return res;
    }
};
