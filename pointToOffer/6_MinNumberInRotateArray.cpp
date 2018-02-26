#include <iostream>


/* 给出被旋转过一次的数组的最小值 */
class Solution {
public:
	int minNumberInRotateArray(std::vector<int> rotateArray) {
		if (rotateArray.size() <= 0)
			return 0;
		int left = 0;
		int right = rotateArray.size() - 1;
		int mid = 0;
		while (rotateArray[left] >= rotateArray[right]) {
			if (right - left == 1) {
				mid = right;
				break;
			}

			mid = left + (right - left >> 1);
			if (rotateArray[mid] >= rotateArray[left]) {
				left = mid;
			}
			else {
				right = mid;
			}
		}
		return rotateArray[mid];
	}
};

int main()
{
	std::vector<int> v = { 5, 6, 7, 8, 1, 2, 3, 4 };
	Solution so;
	std::cout << so.minNumberInRotateArray(v);
	return 0;
}

