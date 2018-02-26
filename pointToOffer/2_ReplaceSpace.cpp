#include <iostream>

/* 字符串替换 */
#if 1
class Solution {
public:
	void replaceSpace(char * str, int length) {
		if (str == nullptr || length <= 0)
			return;

		//hello world
		int spaceCont = 0;
		int strSize = strlen(str);
		char * strTail = str + strSize - 1;

		for (auto i = 0; i < strSize; ++i) {
			if (isspace(str[i])) {
				spaceCont++;
			}
		}

		int totalSize = strSize + (spaceCont << 1);
		if (totalSize > length)
			return;
		char * newTail = str + totalSize - 1;
		int index = totalSize - 1;
		for (auto i = strSize - 1; i >= 0; --i) {
			if (isspace(str[i])) {
				str[index--] = '%';
				str[index--] = '0';
				str[index--] = '2';
			}
			else {
				str[index--] = str[i];
			}
		}
		str[totalSize] = '\0';
	}
};

int main()
{
	char  str[30] = "hello wo rld";
	Solution so;
	so.replaceSpace(str, 30);
	std::cout << str << std::endl;
	return 0;
}
#endif

