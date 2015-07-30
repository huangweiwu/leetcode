// 给定一个城市的所有房子的信息，包括[li, ri, hi]，分别表示其左右横坐标和纵坐标，求这n个房子组成的城市的外观
// 用一组[xi, yi]返回
//	思路：保存所有存活的建筑，用一个priority_queue结构保存，根据建筑的高度排序，并将新建筑的左x坐标与最高建筑的右坐标比较
//		curX = 最高建筑的右坐标；buildings[cur][0] = 当前建筑的左坐标
//		如果新建筑的左x坐标 > 最高建筑的右坐标，将所有右坐标小于新建筑左坐标的弹出，curX不变，curH为最高建筑的高度，将这两者组合压入res
//		如果新建筑的左x坐标 < 最高建筑的右坐标，将所有左x坐标相等的新建筑入队列，并将curX置为buildings[cur][0]，curH为最高建筑的高度，将这两者组合压入res

//	多一步cur >= len的判断是因为，while为true是由后半部分引起的，当最后一个建筑与其他建筑不相交，会出现这样的情况
//	多一步res.back().second != cur_H的判断是因为，返回结果中不能存在连续的高度相等的建筑

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> res;
        int cur=0, cur_X, cur_H = -1,  len = buildings.size();
        priority_queue<pair<int, int>> liveBlg; // first: height, second, end time
        while(cur<len || !liveBlg.empty())
        { // if either some new building is not processed or live building queue is not empty
            cur_X = liveBlg.empty() ? buildings[cur][0] : liveBlg.top().second; // next timing point to process

            if(cur >= len || buildings[cur][0] > cur_X)
            {	// first check if the current tallest building will end before the next timing point
				// 如果当前最高的建筑右x坐标小于新建筑的左x坐标
                  // pop up the processed buildings, i.e. those  have height no larger than cur_H and end before the top one
				// 弹出已经处理过的建筑，即右x坐标比当前建筑的左x坐标小的建筑
                while(!liveBlg.empty() && ( liveBlg.top().second <= cur_X) ) 
					liveBlg.pop();
            }
            else
            {	// if the next new building starts before the top one ends, process the new building in the vector
				// 如果当前最高的建筑右x坐标大于新建筑的左x坐标，处理新建筑；将所有同样起点的新建筑加入liveBlg中
				// cur_X为新建筑的左x坐标
                cur_X = buildings[cur][0];
                while(cur<len && buildings[cur][0] == cur_X)  // go through all the new buildings that starts at the same point
                {  // just push them in the queue
                    liveBlg.push(make_pair(buildings[cur][2], buildings[cur][1]));
                    cur++;
                }
            }
            cur_H = liveBlg.empty() ? 0 : liveBlg.top().first; // output the top one	输出最高建筑的高度
            if(res.empty() || (res.back().second != cur_H))
				// 如果有连续的建筑高度一致，则输出中只需要保留第一个
				res.push_back(make_pair(cur_X, cur_H));
        }
        return res;
    }
};

int main() {
	Solution so;
	
	vector<string> words;
	words.push_back("oath");
	words.push_back("eath");
	char ch1[4] = {'o','a','a','n'};
	char ch2[4] = {'e','t','a','e'};
	char ch3[4] = {'i','h','k','r'};
	char ch4[4] = {'i','f','l','v'};
	vector<char> v1(ch1, ch1 + 4);
	vector<char> v2(ch2, ch2 + 4);
	vector<char> v3(ch3, ch3 + 4);
	vector<char> v4(ch4, ch4 + 4);
	vector<vector<char>> board;
	board.push_back(v1);
	board.push_back(v2);
	board.push_back(v3);
	board.push_back(v4);
	
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = new ListNode(6);

	ListNode* headA = new ListNode(3);
	ListNode* headB = new ListNode(2);
	headB->next = headA;
	

	TreeNode* head1 = new TreeNode(1);
	//head1->left = new TreeNode(2);
	//head1->left = new TreeNode(2);
	//head1->left->left = new TreeNode(2);

	TreeLinkNode* root = new TreeLinkNode(1);
	root->left = new TreeLinkNode(2);
	root->right = new TreeLinkNode(3);
	
	int t1[3] = {2, 9, 10};
	int t2[3] = {3, 7, 15};
	int t3[3] = {5, 12, 12};
	int t4[3] = {15, 20, 10};
	int t5[3] = {23, 24, 8};
	vector<int> v11(t1, t1+3);
	vector<int> v12(t2, t2+3);
	vector<int> v13(t3, t3+3);
	vector<int> v14(t4, t4+3);
	vector<int> v15(t5, t5+3);
	vector<vector<int> > v;
	v.push_back(v11);
	v.push_back(v12);
	v.push_back(v13);
	v.push_back(v14);
	v.push_back(v15);
	so.getSkyline(v);

	pair<int, int> p1 = make_pair<int, int>(3,1);
	pair<int, int> p2 = make_pair<int, int>(2,2);
	if(p1 < p2)
		cout << 1 << endl;

	system("pause");
	return 0;
}