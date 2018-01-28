/**********************************************************************************
*
* Given an integer, convert it to a roman numeral.
*
* Input is guaranteed to be within the range from 1 to 3999.
*
**********************************************************************************/

#include <iostream>
#include <string>
#include <vector>

#if 1
class Solution {
public:
	std::string intToRoman(int num) {
		std::string symbol[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
		int value[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
		std::string ret;
		for (int i = 0; num != 0; i++) {
			while (num >= value[i]) {
				num -= value[i];
				ret += symbol[i];
			}
		}
		return ret;
	}
};

int main()
{
	int input;
	Solution so;
	while (1) {
		std::cin >> input;
		std::cout << so.intToRoman(input) << std::endl;
	}
	return 0;
}
#endif
