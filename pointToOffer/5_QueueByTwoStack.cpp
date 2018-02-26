#include <iostream>
#if 1

/* 用两个栈实现一个队列 */
class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}
	int pop() {
		if (!stack2.empty()) {
			int res = stack2.top();
			stack2.pop();
			return res;
		}

		while (!stack1.empty()) {
			stack2.push(stack1.top());
			stack1.pop();
		}
		int res = stack2.top();
		stack2.pop();
		return res;
	}

private:
	std::stack<int> stack1;
	std::stack<int> stack2;
};

int main()
{
	Solution so;
	so.push(1);
	so.push(2);
	so.push(3);
	so.push(4);
	so.push(5);
	std::cout << so.pop() << std::endl;
	std::cout << so.pop() << std::endl;
	std::cout << so.pop() << std::endl;
	std::cout << so.pop() << std::endl;
	std::cout << so.pop() << std::endl;
	return 0;
}
#endif

