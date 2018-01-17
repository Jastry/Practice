class Solution{
public:
	int reverse(int x) {
		int res = 0;
		while (x != 0) {
			int unit = x % 10;
			if (res > 214748364 || res < -214748364)
				return 0;
			res = res * 10 + unit;
			x /= 10;
		}
		return res;
	}
};

int main()
{


	Solution so;
	while (1) {
		int input = 0;
		std::cin >> input;
		std::cout << so.reverse(input) << std::endl;
	}
	return 0;
}

