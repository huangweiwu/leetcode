#include<iostream>
#include<vector>
using namespace std;

// 给定n个课程，这些课程中有一些必须先修其他课程，给定其中的先后关系，比如课程0必须在课程1后上，则给定[0, 1]
//  给定所有的这些先后关系，求是否能修完这些课程
//	思路：如果课程中不存在环，则可以修完；存在环则不行
//		深度优先搜索；并对访问过不存在环的结点做标记，加快搜索速度


bool visit[10000001];		//是否已经访问过  
bool mark[10000001];		//是否已经验证过该节点  

class Solution {  
public:  
    static bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {  
        int len=prerequisites.size();  
        if(len==0){  
            return true;  
        }  
        vector<vector<int>> graph(numCourses, vector<int>());   //邻接表表示的图  
        for(int i=0; i<len; i++){  
			graph[prerequisites[i].first].push_back(prerequisites[i].second);
        }
        memset(visit, 0, numCourses * sizeof(bool)); 
        memset(mark, 0, numCourses * sizeof(bool));  
          
        for(int i=0; i<numCourses; i++){  
            if(DFSHasCircle(graph, visit, mark, i)){  
                return false;  
            }  
        }  
        return true;  
    }  
      
    // 判断是否有环，思路为若存在一个节点访问了2次，则表明有环  
    static bool DFSHasCircle(vector<vector<int>>& graph, bool* visit, bool* mark, int current){  
        if(visit[current]){  
            return true;
        }  
        if(mark[current]){  
            return false;  
        }
        visit[current] = true;      //标记已经访问过
          
        for(int i=0; i<graph[current].size(); i++){  
            if(DFSHasCircle(graph, visit, mark, graph[current][i])){  
                return true;
            }
        }
        
        mark[current] = true;       //表示以该顶点开始的可达的所有节点构成的子图均没有环  
        visit[current] = false;     //去掉已经访问过的标记
        return false;  
    }  
};  