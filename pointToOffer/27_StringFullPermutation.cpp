#include <iostream>
/* 用两个栈实现*/

/* 字符串全排列*/
template <typename T>
inline void swap(T* array, unsigned int i, unsigned int j)
{
	T t = array[i];
	array[i] = array[j];
	array[j] = t;
}

/*
* 递归输出字符串的全排列
*/

class Solution {
public:
	std::vector<std::string> Permutation(std::string str) {
		if (str.size() <= 0)
			return res;
		Permutation(str, 0);
		auto setIt = set.begin();
		res.reserve(set.size());
		while (setIt != set.end()) {
			res.push_back(*setIt);
			setIt++;
		}
		return res;
	}
protected:
	void Permutation(std::string str, int idx) {
		if (idx == str.size()) {
			set.insert(str);
			return;
		}
		for (int i = idx; i < str.size(); ++i) {
			swap(&str[idx], &str[i]);
			Permutation(str, idx + 1);
			swap(&str[idx], &str[i]);
		}
	}
	void swap(char * a, char * b) {
		char temp = *a;
		*a = *b;
		*b = temp;
	}
private:
	std::set<std::string> set;
	std::vector<std::string> res;
};

std::vector< std::string > vs;
void FullArray(char * a, int strLen, int idx) {
	if (idx >= strLen)
		vs.push_back(a);

	for (auto i = idx; i < strLen; ++i) {
		swap(a, i, idx);
		FullArray(a, strLen, idx + 1);
		swap(a, i, idx);
	}
}

int main()
{	
	/*char a[] = "abc";
	FullArray(a, 3, 0);
	std::cout << vs.size() << std::endl;*/
	Solution so;
	so.Permutation(std::string("aabc"));

	return 0;
}
