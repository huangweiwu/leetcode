// 复制一幅无向图
// 构造一个源地址和新地址对应的map，每次复制新结点的时候，查看该map，确定结点是否已经创建过，如果没有则创建
//	由于需要快速查找，所以采用无序map

class Solution {
public:
	unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> clone;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node && !clone[node]) {
			// 如果当前结点非空，且其复制结点还没创建，则创建
			clone[node] = new UndirectedGraphNode(node->label);
			for(auto n : node->neighbors)
				clone[node]->neighbors.push_back(cloneGraph(n));
		}
		return clone[node];
    }
};
