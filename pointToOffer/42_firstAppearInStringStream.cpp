#include <iostream>

/* 找出字符流中第一个只出一次的字符 */
#if 1
class Solution
{
public:
	//Insert one char from stringstream
	void Insert(char ch)
	{
		if (++m_hash[ch] == 1)
			m_res.push(ch);
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		if (m_res.empty())
			return '#';
		while (!m_res.empty() && m_hash[m_res.front()] != 1) {
			m_res.pop();
		}
		if (m_res.empty())
			return '#';

		return m_res.front();
	}

private:
	int m_hash[128];
	std::queue<char> m_res;
};


int main()
{
	Solution so;
	std::string str = "google";
	for (int i = 0; i < str.size(); ++i) {
		so.Insert(str[i]);
	}
	char ch = so.FirstAppearingOnce();
	return 0;
}
#endif

