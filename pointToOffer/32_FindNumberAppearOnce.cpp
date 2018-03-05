#include <iostream>

#if 1
/* 一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。*/
class Solution {
public:
	void FindNumsAppearOnce(std::vector<int> data,int* num1,int *num2) {
		if (data.size() <= 2)
			return;

		int resultExclusiveOR = data[0];
		for (auto i = 1; i < data.size(); ++i) {
			resultExclusiveOR ^= data[i];
		}

		unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOR);

		for (auto i = 0; i < data.size(); ++i) {
			if (IsBits1(data[i], indexOf1))
				*num1 ^= data[i];
			else
				*num2 ^= data[i];
		}
	}
private:
	int FindFirstBitIs1(int num) {
		int index = 0;

		while (((num & 1) == 0) && (index < 8 * sizeof(int))) {
			num = (num >> 1);
			++index;
		}
		return index;
	}

	bool IsBits1(int number, int index) {
		number >>= index;
		return (number & 1);
	}
};

int main()
{
	std::vector<int> arr = { 1, 2, 3, 4, 5, 56 ,6, 7, 8, 9, 5, 6, 7, 8, 3, 1, 2, 9 };
	Solution so;
	int a = 0, b = 0;
	so.FindNumsAppearOnce(arr, &a, &b);
	return 0;
}
#endif

