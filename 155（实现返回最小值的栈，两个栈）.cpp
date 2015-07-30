// 实现能够在常数时间返回最小值的栈
//	思路：用两个栈，一个返回保存数据，一个保存最小值


class MinStack {
private:
	stack<int> data;
	stack<int> minvalue;
public:
    void push(int x) {
		data.push(x);
		if(minvalue.empty()) {
			minvalue.push(x);
			return;
		}
		if(minvalue.top() < x)
			minvalue.push(minvalue.top());
		else
			minvalue.push(x);
    }

    void pop() {
		if(!data.empty()) {
			data.pop();
			minvalue.pop();
		}
    }

    int top() {
		if(data.empty())
			return -1;
		return data.top();
    }

    int getMin() {
		return minvalue.top();
    }
};