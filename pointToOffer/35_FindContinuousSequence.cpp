#include <iostream>

/* 一串连续正数和为 K */
class Solution {
public:
	std::vector<std::vector<int> > FindContinuousSequence(int sum) {
		int left = 1, right = 1, tmp = 1;
		std::vector< std::vector<int> > res;
		while (left <= right) {
			right++;
			tmp += right;
			while (tmp > sum) {
				tmp -= left;
				left++;
			}
			if (tmp == sum && left != right) {
				std::vector<int> a;
				for (int i = left; i <= right; ++i) {
					a.push_back(i);
				}
				res.push_back(a);
			}
		}
		return res;
	}
};

int main()
{
	Solution so;
	std::vector< std::vector<int> > res = so.FindContinuousSequence(100);
	return 0;
}
