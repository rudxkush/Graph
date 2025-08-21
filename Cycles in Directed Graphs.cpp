/*
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge from vertex u to v.

Input: V = 4, edges[][] = [
                                        [0, 1], 
                                        [0, 2],
                                        [1, 2],
                                        [2, 0],
                                        [2, 3]
                                       ]
Output: true
Explanation: The diagram clearly shows a cycle 0 → 2 → 0

Two Approaches - 
DFS
Topological Sort
Both are equally good.



        2 → 3
   ↙   ↑
 0 → 1
 ↓
 2 


First Approach Code -
Keep something like a pathVisited along with visited so that we would have an idea at the time of DFS traverse  
that okay this node is visited but also pathVisited that means it is coming again and again in the same path. 
Thus, a cycle exists.
*/
bool dfs(vector<vector<int>>& graph, int vertex, vector<bool>& visited, 
         vector<bool>& pathVisited) {
  visited[vertex] = true;
  pathVisited[vertex] = true;
  
  for(auto neighbour : graph[vertex]) {
    if(!visited[neighbour]) {
      if(dfs(graph, neighbour, visited, pathVisited)) return true;
    } else if(pathVisited[neighbour]) return true;
  }
  
  pathVisited[vertex] = false;
  return false;
}

bool doesExist(int V, vector<vector<int>>& edges) {
  vector<vector<int>> graph(V);
  for(auto edge : edges) 
    graph[edge[0]].push_back(edge[1]);
  
  vector<bool> visited(V, false);
  vector<bool> pathVisited(V, false);

  for(int i = 0; i < V; i++) {
    if(!visited[i]) {  
      if(dfs(graph, i, visited, pathVisited)) 
        return true;
    }
  }
  
  return false;
}
int main() 
{
  vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 0}, {2, 3}};
  int V = 4; // Zero Indexed Vertices.
  cout << "Does cycle exist in the provided graph? ";
  if(doesExist(V, edges))
    cout << "True" << endl;
  else 
    cout << "false" << endl;
  return 0;
}
/*
Second Approach Code -

In Topological Sort, you always get a linear order of the vertices and so if anything bigger than the number of vertices is coming
then it must have a cycle as that is the only reason that explains why it is exploring already stored vertices again and again.
*/

bool topoSort(int V, vector<vector<int>>& graph, vector<int>& inDegree) {
	// Kahn’s Algorithm
	queue<int> q;
	vector<int> linearOrder;
	for(int i = 0; i < V; i++) {
                  if(inDegree[i] == 0) q.push(i);
            }
	while(!q.empty()) {
		int vertex = q.push();
		linearOrder.push(vertex);

		for(auto neighbour : graph[vertex]) {
			inDegree[neighbour] - 1;
			if(inDegree[neighbour] == 0) q.push(neighbour);
 		}
}
return linearOrder.size() == V;
}

bool doesExist(int V, vector<vector<int>>& edges) {
    vector<vector<int>> graph(V);
    vector<int> inDegree(V, 0);

    for(auto edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        inDegree[edge[1]]++;
    }

    // If topoSort fails → cycle exists
    return !topoSort(V, graph, inDegree);
}

int main() {
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 0}, {2, 3}};
    int V = 4; // Zero Indexed Vertices.

    cout << "Does cycle exist in the provided graph? ";
    if(doesExist(V, edges))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}




