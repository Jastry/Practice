#include <iostream>
/*Generate Parentheses 全排列*/
#if 1
/* 给 n 个括号，求正确匹配的形式有多少种 */
class Solution {
public:
	std::vector< std::string > generateParenthesis(int n) {
		std::vector< std::string > result;
		std::string str;
		generator(result, n, n, str);
		return result;
	}
private:
	void generator(std::vector< std::string > &result, int left, int right, std::string str)
	{
		if ((left == 0) && (right == 0)) {
			result.push_back(str);
			return;
		}
		if (left > 0) {
			generator(result, left - 1, right, str + '(');
		}
		if (right > 0 && right > left) {
			generator(result, left, right - 1, str + ')');
		}
	}
};

int main()
{
	int n = 3;
	Solution so;
	std::vector< std::string > r = so.generateParenthesis(n);
	
	for (size_t i = 0; i < r.size(); ++i) {
		std::cout << r[i] << std::endl;
	}
	return 0;
}
#endif
