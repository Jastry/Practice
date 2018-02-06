#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
	/*
	 * Letter Combinations of a Phone Number
	 * 全排列	
	 */
class Solution {
	//3毫秒
public:
	std::vector< std::string > letterCombinations(std::string digits) {
		char phone[10][4] = {
			{ ' ','\0','\0', '\0' },	//0
			{ '\0','\0','\0','\0' },	//1
			{ 'a', 'b', 'c', '\0' },	//2
			{ 'd', 'e', 'f', '\0' },	//3
			{ 'g', 'h', 'i', '\0' },	//4
			{ 'j', 'k', 'l', '\0' },	//5
			{ 'm', 'n', 'o', '\0' },	//6
			{ 'p', 'q', 'r', 's'  },	//7
			{ 't', 'u', 'v', '\0' },	//8
			{ 'w', 'x', 'y', 'z'  },	//9
		};
		std::vector< std::string > result;
		if (digits.size() <= 0) {
			result.push_back("");
			return result;
		}
		for (int i = 0; i < digits.size(); ++i) {
			if (!isdigit(digits[i])) {
				return std::vector< std::string >();
			}
			int d = digits[i] - '0';
			if (result.size() <= 0) {
				for (int j = 0; j < 4 && (phone[d][j] != '\0'); ++j)
				{
					std::string str;
					str += phone[d][j];
					result.push_back(str);
				}
				continue;
			}
			std::vector< std::string > temp;
			for (int j = 0; j < result.size(); ++j) {
				for (int k = 0; k < 4 && (phone[d][k] != '\0'); ++k) {
					std::string str = result[j] + phone[d][k];
					temp.push_back(str);
				}
			}
			result = temp;
		}
		return result;
	}
};

#if 0
//0毫秒
static int x = [](){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	return 0;
}();

std::string letters[] = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
std::map<char, std::string> cleanUp = { { '2', "abc" }, { '3', "def" },
{ '4', "ghi" }, { '5', "jkl" }, { '6', "mno" },
{ '7', "pqrs" }, { '8', "tuv" }, { '9', "wxyz" } };

class Solution1 {
	int resIndex = 0;
public:
	std::vector< std:: string > letterCombinations(std::string digits) {
	std::map<char, std::string>::iterator it;

		int size = digits.length();
		int newSize = 0;
		std::string newDigits(size, '\0');
		unsigned long numStrings = size > 0 ? 1 : 0;
		if (size > 0)
		{
			for (int i = 0; i < size; i++)
			{
				it = cleanUp.find(digits[i]);
				if (it != cleanUp.end())
				{
					numStrings *= it->second.size();
					newDigits[newSize++] = digits[i];
				}
			}
			newDigits.resize(newSize);

			// Enough digits and BOOM!
			// if (numStrings > retVal.max_size())
			// {
			//     newSize = 0;
			// }

		}
		std::string ph(newSize, ' ');
		std::vector< std::string> retVal(numStrings);
		//vector<string> retVal;
		if (newSize > 0)
		{
			dfs(newDigits, 0, ph, retVal);
		}

		return retVal;
	}

	inline void dfs(const std::string &newDigits, size_t cur, std::string path, std::vector< std::string > &res)
	{
		if (cur == newDigits.size())
		{
			//res.push_back(path);
			res[resIndex++] = path;
			return;
		}

		for (char c : letters[newDigits[cur] - '2'])
		{
			path[cur] = c;
			dfs(newDigits, cur + 1, path, res);
		}
	}
};
#endif
int main()
{
	Solution so;
	std::vector< std::string > res;
	res = so.letterCombinations((std::string)"456");
	return 0;
}

