#include<iostream>
#include<string>
#include<queue>
using namespace std;

// 用两个队列实现栈用
// 思路：用两个队列存储
class Stack {
public:
    // Push element x onto stack.
	queue<int> q1;
	queue<int> q2;
    void push(int x) {
		if(q1.empty() && q2.empty()) {
			q1.push(x);
			return;
		}
		if(q1.empty())
			q2.push(x);
		else
			q1.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        if(q1.empty() && q2.empty())
			return;
		if(q1.empty()) {
			while(q2.size() > 1) {
				q1.push(q2.front());
				q2.pop();
			}
			q2.pop();
		}
		else {
			while(q1.size() > 1) {
				q2.push(q1.front());
				q1.pop();
			}
			q1.pop();
		}
    }

    // Get the top element.
    int top() {
		int ret = -1;
        if(q1.empty() && q2.empty())
			return ret;
		if(q1.empty()) {
			while(q2.size() > 1) {
				q1.push(q2.front());
				q2.pop();
			}
			ret = q2.front();
			q1.push(q2.front());
				q2.pop();
		}
		else {
			while(q1.size() > 1) {
				q2.push(q1.front());
				q1.pop();
			}
			ret = q1.front();
			q2.push(q1.front());
				q1.pop();
		}
		return ret;
    }

    // Return whether the stack is empty.
    bool empty() {
        if(q1.empty() && q2.empty())
			return true;
		else
			return false;
    }
};

int main() {
	Stack s;
	s.push(1);
	s.push(2);
	cout << s.top() << endl;
	cout << s.top() << endl;

	system("pause");
	return 0;
}