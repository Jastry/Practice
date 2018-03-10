#include <iostream>

/* 数组中第一个重复的数 */
#if 1
class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication) {
		std::unordered_map<int, int> mp;
		for (int i = 0; i < length; ++i) {
			if (++mp[numbers[i]] == 2) {
				*duplication = numbers[i];
				return true;
			}
		}
		return false;
	}
};

int main()
{
	Solution so;
	int a[] = { 2, 3, 1, 0, 2, 5, 3 };
	int b = 0;
	so.duplicate(a, sizeof(a) / sizeof(int), &b);

	return 0;
}
#endif
