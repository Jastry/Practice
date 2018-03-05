#include <iostream>

/* 丑数即只包含因子为2 3 5 的数 */
#if 1
class Solution {
public:
	int GetUglyNumber_Solution(int index) {
		if (index < 7)	return index;
		std::vector< int > res(index);
		res[0] = 1;
		int t2 = 0, t3 = 0, t5 = 0, i;
		for (i = 1; i < index; ++i) {
			res[i] = std::min(res[t2] * 2, std::min(res[t3] * 3, res[t5] * 5));
			if (res[i] == res[t2] * 2)	t2++;
			if (res[i] == res[t3] * 3)	t3++;
			if (res[i] == res[t5] * 5)	t5++;
		}
		return res[index - 1];
	}
};

int main() {
	int input, res = -1;
	Solution so;
	while (std::cin >> input) {

		res = so.GetUglyNumber_Solution(input);
		std::cout << res << std::endl;
	}
	return 0;
}
#endif
