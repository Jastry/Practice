
/********************************************************************************** 
* 
* Write a function to find the longest common prefix string amongst an array of strings.
* 
*               
**********************************************************************************/

/* Longest Common Prefix */

/*
 *	方法一
 *	匹配最长字符串前缀
 */

class Solution1 {
public:
	std::string longestCommonPrefix(std::vector<std::string>& strs) {
		if (strs.empty())
			return std::string();
		std::string prefix = strs[0];
		size_t index = 0;
		for (size_t i = 1; i < strs.size(); ++i) {
			while (strs[i].find(prefix) != 0) {
				prefix = prefix.substr(0, prefix.size() - 1);
				if (prefix.size() == 0)
					return prefix;
			}
		}
		return prefix;
	}
};


/*
 *	方法二	
 *	垂直扫描，判断每个字符串是否都有第一个字符串对应下表的字符
 */
class Solution {
public:
	std::string longestCommonPrefix(std::vector<std::string>& strs) {
		if (strs.empty())
			return std::string();
		std::string prefix = strs[0];
		for (size_t i = 0; i < prefix.size(); ++i) {
			for (size_t j = 1; j < strs.size(); ++j) {
				char ch = prefix[i];
				if (ch != strs[j][i]) {
					prefix = prefix.substr(0, i);
					return prefix;
				}
			}
			return prefix;
		}
	}
};

