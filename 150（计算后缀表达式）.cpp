// 计算后缀表达式
//	思路1：借助栈，读到数字则压入栈；读到符号则从栈中读出两个数进行相应计算

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
		int op1, op2;
		for(int i=0; i<tokens.size(); i++) {
			if(tokens[i] == "+") {
				op1 = nums.top();
				nums.pop();
				op2 = nums.top();
				nums.pop();
				nums.push(op2 + op1);
			}
			else if(tokens[i] == "-") {
				op1 = nums.top();
				nums.pop();
				op2 = nums.top();
				nums.pop();
				nums.push(op2 - op1);
			}
			else if(tokens[i] == "*") {
				op1 = nums.top();
				nums.pop();
				op2 = nums.top();
				nums.pop();
				nums.push(op2 * op1);
			}
			else if(tokens[i] == "/") {
				op1 = nums.top();
				nums.pop();
				op2 = nums.top();
				nums.pop();
				nums.push(op2 / op1);
			}
			else
				nums.push(atoi(tokens[i].c_str()));
		}
		return nums.top();
    }
};

//	思路2：递归
int evalRPN(vector<string> &n) {
    string s = n.back(); n.pop_back();
    if ( s== "*" || s=="/" || s=="+" || s == "-" ){
        int r2 = evalRPN(n);
        int r1 = evalRPN(n);
        if ( s=="*") return r1*r2;
        if ( s=="/") return r1/r2;
        if ( s=="+") return r1+r2;
        if ( s=="-") return r1-r2;
    }
    else
        return atoi(s.c_str());
}

int main() {
	Solution so;
	
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = new ListNode(6);

	

	TreeNode* head1 = new TreeNode(1);
	//head1->left = new TreeNode(2);
	head1->left = new TreeNode(2);
	head1->left->left = new TreeNode(2);
	
	TreeLinkNode* root = new TreeLinkNode(1);
	root->left = new TreeLinkNode(2);
	root->right = new TreeLinkNode(3);
	int a[6] = {3, 30, 34, 5, 9, 1};
	vector<int> v(a, a+6);
	
	system("pause");
	return 0;
}