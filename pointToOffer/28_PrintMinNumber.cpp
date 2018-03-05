#include <iostream>
#include <string>
#include <vector>

/* 把数组中所有数字拼接起来排成最小的数字 */
class Solution {
public:
	std::string PrintMinNumber( std::vector<int> numbers) {
		std::string res = "";
		if (numbers.size() <= 0)	return res;
		sort(numbers.begin(), numbers.end(), cmp);
		for (auto i = 0; i < numbers.size(); ++i) {
			res += std::to_string(numbers[i]);
		}
		return res;
	}
	static bool cmp(int a, int b) {
		std::string str1 = std::to_string(a) + std::to_string(b);
		std::string str2 = std::to_string(b) + std::to_string(a);
		return str1 < str2;
	}
};

int main()
{
    std::vector< std::string > a = { "456", "789","123" };
    Solution so;
    std::string res = so.PrintMinNumber(a);
    std::cout << res << std::endl;
    return 0;
}
