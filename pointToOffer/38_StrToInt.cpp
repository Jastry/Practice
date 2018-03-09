#include <iostream>

/* 实现 atoi 函数*/
class Solution {
public:
	int StrToInt(std::string str) {
		int i = 0;
		int ret = 0;
		while (isspace(str[i]))	i++;

		bool sign = 0;
		if (str[i] == '-' || str[i] == '+') {
			sign = (str[i] == '-');
			++i;
		}
		for (; i < str.size(); ++i) {
			if (!isdigit(str[i]))	return 0;
			int unit = str[i] - '0';
			if (!sign) {
				if (ret > (INT_MAX - unit) / 10)
					return INT_MAX;
			}
			else {
				if (-ret < (INT_MIN + unit) / 10)
					return INT_MIN;
			}
			ret = ret * 10 + unit;
		}
		return sign ? -ret : ret;
	}
};

int main()
{
	std::string str = "+12345a67";
	Solution so;
	int res = so.StrToInt(str);
	return 0;
}

