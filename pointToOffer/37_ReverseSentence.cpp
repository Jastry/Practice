#include <iostream>

/* student a am i -> i am a student */
#if 1
class Solution {
public:
	std::string ReverseSentence(std::string str) {
		if (str.empty())	return str;
		std::string res = "", tmp = "";
		for (int i = 0; i < str.size(); ++i) {
			if (str[i] == ' ') {
				res = " " + tmp + res;
				tmp = "";
			}
			else
				tmp += str[i];
		}

		res  = tmp + res;
		return res;
	}
};

int main()
{
	std::string str = "student a am i";
	Solution so;
	std::string res = so.ReverseSentence(str);
	return 0;
}
#endif
