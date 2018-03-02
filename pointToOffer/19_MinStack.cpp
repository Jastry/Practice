#include <iostream>

/* 实现一个栈,每次可以得到栈的最小值 */
#if 1
class Solution {
public:
	void push(int value) {
		m_st.push(value);
		if (m_smin.empty()) {
			m_smin.push(value);
		}
		else {
			if (value < m_smin.top())
				m_smin.push(top());
		}
	}
	void pop() {
		int top = m_st.top();
		m_st.pop();
		if (m_smin.top() == top) {
			m_smin.pop();
		}
	}
	int top() {
		return m_st.top();
	}

	int min() {
		return m_smin.top();
	}
private:
	std::stack<int> m_st;
	std::stack<int> m_smin;
};

int main()
{
	Solution so;
	so.push(4);
	so.push(3);
	so.push(2);
	so.push(1);
	so.push(0);

	int ret = so.min();

	return 0;
}

#endif

