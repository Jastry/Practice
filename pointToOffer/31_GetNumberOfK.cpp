#include <iostream>

/* 找出一个有序数组中 K 出现的次数 */
class Solution {
public:
	int GetNumberOfK(std::vector<int> data, int k) {
		int idx = -1;
		if (-1 == (idx = BinarySearch(data, k)))
			return 0;

		int cnt = 1, tmp = idx;
		while (tmp > 0 && data[--tmp] == k)	++cnt;
		tmp = idx;
		while (tmp < data.size()-1 && data[++tmp] == k) ++cnt;
		return cnt;
	}
private:
	int BinarySearch(const std::vector<int> & data, int k) {
		int left = 0;
		int right = data.size() - 1;
		while (left <= right) {
			int mid = right + left >> 1;
			if (data[mid] > k) right = mid - 1;
			else if (data[mid] < k) left = mid + 1;
			else return mid;
		}
		return -1;
	}
};

int main()
{
	std::vector<int> a = {1, 1 ,1 ,1, 1, 1 ,1 ,1, 1};
	Solution so;
	std::cout << so.GetNumberOfK(a, 1);
	return 0;
}
