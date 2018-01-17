class Solution {
public:

	bool isPalindrome(int x) {
		return (x >= 0 && x == reverse(x));
	}
private:
	int reverse(int x)
	{
		int y = 0;
		while (x > 0) {
			int n = x % 10;
			x = x / 10;
			y = y * 10 + n;
		}
		return y;
	}
};

int main()
{
	int input;
	Solution so;
	while (1) {
		std::cin >> input;
		std::cout << so.isPalindrome(input) << std::endl;
	}
	return 0;
}
