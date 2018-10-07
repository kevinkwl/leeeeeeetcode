/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    unordered_map<int, UndirectedGraphNode*> nodeMap;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node)  
            return NULL;
        if (nodeMap.count(node->label) > 0)
            return nodeMap[node->label];
        UndirectedGraphNode *cloned = new UndirectedGraphNode(node->label);
        nodeMap[node->label] = cloned;
        for (UndirectedGraphNode *nb : node->neighbors)
            cloned->neighbors.push_back(cloneGraph(nb));
        return cloned;
    }
};
