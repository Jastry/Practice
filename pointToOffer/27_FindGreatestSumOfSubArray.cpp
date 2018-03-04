#include <iostream>

/* 连续数组的最大值 */
#if 1
class Solution {
public:
	int FindGreatestSumOfSubArray(std::vector<int> array) {
		if (array.size() <= 0)	return 0;
		int curMax = array[0];
		int res = array[0];

		for (auto i = 1; i < array.size(); ++i) {
			curMax += array[i];
			if (curMax < array[i]) {
				curMax = array[i];
			}
			if (curMax > res) {
				res = curMax;
			}
		}
		return res;
	}
};

int main()
{
	std::vector<int> a = { 6, -3, -2, 7, -15, 1, 2, 2 };
	Solution so;
	int res = so.FindGreatestSumOfSubArray(a);
	return 0;
}
#endif
