#include <iostream>
/* 3Sum 将三个数加起来等于零 */
#if 1
class Solution {
public:
	std::vector< std::vector<int> > threeSum(std::vector<int>& nums) {
		std::vector< std::vector<int> > result;
		std::sort(nums.begin(), nums.end());
		int n = nums.size();
		for (int i = 0; i < n - 2; ++i) {
            /* 跳过重复的数字 */
			if (i > 0 && nums[i - 1] == nums[i])
				continue;
			int a = nums[i];
			int low = i + 1;
			int high = n - 1;
			while (low < high) {
				int b = nums[low];
				int c = nums[high];
				int sum = a + b + c;
				if (sum == 0) {
					std::vector<int> v = { a, b, c };
					result.push_back(v);
                    /* 跳过重复的数字 */
					while (low < n - 1 && nums[low] == nums[low + 1]) low++;
                    /* 跳过重复的数字 */
					while (high > 0 && nums[high] == nums[high - 1]) high++;
					low++;
					high--;
				}
				else if (sum > 0) {
                    /* 跳过重复的数字 */
					while (high > 0 && nums[high] == nums[high - 1]) --high;
					--high;
				}
				else {
                    /* 跳过重复的数字 */
					while (low < n - 1 && nums[low] == nums[low + 1]) ++low;
					++low;
				}
			}
		}
		return result;
	}
};

int main()
{
	std::vector<int> v = { 0, 1, 2, 34, 5, 6, 76, 12, 123, 423, 4, 3, 53, -54, 1, -45, -125, -4, -3, -2, -76, -5, -7 };
	Solution so;
	so.threeSum(v);
	return 0;
}
