#include <iostream>
#include <vector>

/* 二维有序数组查找数据 */
#if 1
class Solution {
public:
	bool Find(int target, std::vector< std::vector<int> > array) {

		int y = array.size() - 1;
		int x = 0;
		while (y >= 0 && x < array[y].size()) {
			if (array[y][x] > target)
				y--;
			else if (array[y][x] < target)
				x++;
			else
				return true;
		}
		return false;
	}
};

int main()
{
	std::vector< std::vector<int> > vv;
	vv = { { 1, 3, 4, 5 }, { 6, 7, 8, 9 }, { 10, 11, 12, 13 }, {14, 22, 34, 55} };
	Solution so;
	bool ret = so.Find(1,vv);
	ret = so.Find(1, vv);
	ret = so.Find(5, vv);
	ret = so.Find(10, vv);
	ret = so.Find(13, vv);
	ret = so.Find(14, vv);
	ret = so.Find(55, vv);
	ret = so.Find(56, vv);
	return 0;
}

#endif
