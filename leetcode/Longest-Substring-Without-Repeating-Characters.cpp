
/*  Longest Substring Without Repeating Characters */


/*
 *	Given a string, find the length of the longest substring without repeating characters.
 *
 *	Examples:
 *
 *	Given "abcabcbb", the answer is "abc", which the length is 3.
 *
 *	Given "bbbbb", the answer is "b", with the length of 1.
 *
 *	Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */

class Solution {
public:
	int lengthOfLongestSubstring(std::string s)
	{
		std::map<char, int> m;
		int maxLen = 0;
		int lastRepeateAppear = -1;
		for (int i = 0; i < s.size(); ++i) {
			if (m.find(s[i]) != m.end() && lastRepeateAppear < m[s[i]]) {
				lastRepeateAppear = m[s[i]];	//当前最新出现的重复字符
			}
			if (maxLen < i - lastRepeateAppear) {
				maxLen = i - lastRepeateAppear;
			}
			m[s[i]] = i;
		}
		return maxLen;
	}
};


int main()
{
	std::string s;
	Solution so;
	while (1) {
		std::cin >> s;
		std::cout << so.lengthOfLongestSubstring(s) << std::endl;
	}
	return 0;
}

