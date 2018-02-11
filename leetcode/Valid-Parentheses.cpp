#include <iostream>
class Solution {
public:
	bool isValid(std::string s) {
		if ((s.size() & 1))
			return false;
		std::stack<char> stk;
		for (size_t i = 0; i < s.size(); ++i) {
			switch (s[i]) {
				case ('{') :
					stk.push('{');
					break;
				case ('}'):
					if (stk.size() == 0 || stk.top() != '{')
						return false;
					stk.pop();
					break;
				case ('[') :
					stk.push('[');
					break;
				case (']') :
					if (stk.size() == 0 || stk.top() != '[')
						return false;
					stk.pop();
					break;
				case ('(') :
					stk.push('(');
					break;
				case (')') :
					if (stk.size() == 0 || stk.top() != '(')
						return false;
					stk.pop();
					break;
				default:
					return false;
					break;
			}
		}
		if (stk.size() > 0)
			return false;
		return true;
	}
};
