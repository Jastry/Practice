#include <iostream>

/*假设字符串abcdef，n=3，
 * 设X=abc，Y=def，
 * 所以字符串可以表示成XY，
 * 如题干，问如何求得YX。
 * 假设X的翻转为XT，XT=cba，
 * 同理YT=fed，那么YX=(XTYT)T，
 * 三次翻转后可得结果。
 */

/* 字符串循环移动 */
class Solution {
public:
	std::string LeftRotateString(std::string str, int n) {
		if (str.empty() || n < 0)
			return str;
		int len = str.size();
		n = n % len;
		std::string & tamp = str;
		swap(str, 0, n - 1);
		swap(str, n, len - 1);
		swap(str, 0, len - 1);
	}

	void swap(std::string & str, int start, int end) {

		if (str.size() < end)	throw std::exception("bad end");
		while (start < end) {
			char tamp = str[end];
			str[end] = str[start];
			str[start] = tamp;
			--end, ++start;
		}

	}
};

int main()
{
	std::string str = "abcXYZdef";	//cbaXYZdef
	Solution so;
	so.LeftRotateString(str, 3);
	return 0;
}

