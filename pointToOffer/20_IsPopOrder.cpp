#include <iostream>

/* 判断一个序列是否为栈的弹出序列 */
#if 1

class Solution {
public:
	bool IsPopOrder(std::vector<int> pushV, std::vector<int> popV) {
		if (pushV.empty())
			return false;
		std::vector<int> s;
		for (int i = 0, j = 0; i < pushV.size();) {
			s.push_back(pushV[i++]);
			while (j < popV.size() && s.back() == popV[j]) {
				s.pop_back();
				j++;
			}
		}
		return s.empty();
	}
};

int main()
{
	Solution so;
	std::vector<int> in = { 1, 2, 3, 4, 5 };
	std::vector<int> out1 = { 4, 5, 3, 2, 1 };
	std::vector<int> out2 = { 4, 3, 5, 1, 2 };
	std::cout << so.IsPopOrder(in, out1) << std::endl;
	std::cout << so.IsPopOrder(in, out2) << std::endl;

	return 0;
}
