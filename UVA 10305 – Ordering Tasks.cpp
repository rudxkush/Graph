/*
  John has n tasks to do. Unfortunately, the tasks are not independent and the execution of one task is only possible 
  if other tasks have already been executed. 
  Input: The input will consist of several instances of the problem. Each instance begins with a line containing two integers, 
  1 ≤ n ≤ 100 and m. n is the number of tasks (numbered from 1 to n) and m is the number of direct precedence relations 
  between tasks. After this, there will be m lines with two integers i and j, representing the fact that task i must be 
  executed before task j. An instance with n = m = 0 will finish the input. 
  Output: For each instance, print a line with n integers representing the tasks in a possible order of execution. 
  Sample Input : [5, 4     1, 2      2, 3      1, 3        1, 5     0, 0] 
  Sample Output : [1, 4, 2, 5, 3]
*/

vector<int> executionOrder(vector<int>& input) {
    int n = input[0];
    int m = input[1];
    int counter = 2;
    vector<vector<int>> graph(n + 1);
    vector<int> inDegree(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int src = input[counter];     // 2
        int dst = input[counter + 1]; // 3
        graph[src].push_back(dst);
        inDegree[dst]++;
        counter += 2; // 4
    }
    return topoSort(graph, inDegree, n);
}
vector<int> topoSort(vector<vector<int>>& graph, vector<int>& inDegree, int n) {
    int V = n + 1;
    queue<int> q;
    vector<int> res;
    for (int i = 1; i < V; i++) {
        if (inDegree[i] == 0)
            q.push(i);
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        res.push_back(node);
        for (auto nei : graph[node]) {
            inDegree[nei]--;
            if (inDegree[nei] == 0) {
                q.push(nei);
            }
        }
    }

    return res.size() == n ? res : vector<int>();
}
