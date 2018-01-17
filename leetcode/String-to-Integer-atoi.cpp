class Solution {
public:
	int myAtoi(std::string str) {
		if (str.empty())
			return 0;
		int ret = 0;
		size_t i = 0;
		while (isspace(str[i]))
			i++;
		bool sign = 0;
		if (str[i] == '-' || str[i] == '+'){
			sign = (str[i] == '-');
			i++;
		}
		for (; i < str.size() && isdigit(str[i]); ++i) {
			int unit = str[i] - '0';
			if (!sign) {
				if (ret >(INT_MAX - unit) / 10 )
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
	Solution so;
	std::string input;
	while (1) {
		std::cin >> input;
		std::cout << so.myAtoi(input) << std::endl;

	}
	return 0;
}

