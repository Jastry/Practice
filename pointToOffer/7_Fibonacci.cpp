#include <iostream>

/* 第 N 个斐波那契额数 */
#if 1
class Solution {
public:
	int Fibonacci(int n) {
		if (n <= 0)
			return 0;
		else if (n == 1 || n == 2)
			return 1;
		int a = 1, b = 1, c = 0;
		for (auto i = 3; i <= n; ++i) {
			c = a + b;
			b = a;
			a = c;
		}
		return c;
	}
};

int main()
{
	int in;
	Solution so;
	while (std::cin >> in)
		std::cout << so.Fibonacci(in) << std::endl;
	return 0;
}
#endif

