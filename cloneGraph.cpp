void dfs(UndirectedGraphNode* node, UndirectedGraphNode* cloneStart, 
         unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& nodeMap) { 
             
    for(UndirectedGraphNode* neiNode: node->neighbors) {
        if(!nodeMap.count(neiNode)) {
            UndirectedGraphNode* cloneNei = new UndirectedGraphNode(neiNode->label); 
            cloneStart->neighbors.push_back(cloneNei);
            nodeMap[neiNode] = cloneNei;
            dfs(neiNode, cloneNei, nodeMap);   
        } else {
            cloneStart->neighbors.push_back(nodeMap[neiNode]);
        }  
    }             
}
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> nodeMap;
    
    UndirectedGraphNode* cloneStart = new UndirectedGraphNode(node->label);
    nodeMap[node] = cloneStart;
    dfs(node, cloneStart, nodeMap);
    
    return cloneStart;
}
