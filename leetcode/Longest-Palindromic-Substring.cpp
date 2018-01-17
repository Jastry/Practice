
/******************************************************************************************************************************
*   Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
*   
*   Example:
*   
*   Input: "babad"
*   
*   Output: "bab"
*   
*   Note: "aba" is also a valid answer.
*   Example:
*   
*   Input: "cbbd"
*   
*   Output: "bb"
******************************************************************************************************************************/
class Solution{
public:
	std::string longestPalindrome(std::string s) {
		if (s.size() <= 1)
			return s;
		std::string longest;
		std::string tamp;
		for (size_t i = 0; i < s.size(); ++i) {
			tamp = _FindPalindrome(s, i, i);
			if (longest.size() < tamp.size())
				longest = tamp;
			/*  两个相同字符的情况 */
			tamp = _FindPalindrome(s, i, i + 1);
			if (tamp.size() > longest.size())
				longest = tamp;
		}
		return longest;
	}
private:
	std::string _FindPalindrome(const std::string& str, int left, int right)
	{
		int n = str.size();
		int r = right;
		int l = left;
		while (l >= 0 && r <= n - 1 && str[l] == str[r]) {
			l--;
			r++;
		}
		return str.substr(l+1, r - l - 1);
	}
};

