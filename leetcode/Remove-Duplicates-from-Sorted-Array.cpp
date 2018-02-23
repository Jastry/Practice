#include <iostream>

/* 不同元素的个数 */
#if 1
class Solution {
public:
	int removeDuplicates(std::vector<int>& nums) {
		std::unordered_set<int> foo;
		std::pair< std::unordered_set<int>::const_iterator, bool > res;
		for (auto i = nums.begin(); i != nums.end(); ++i) {
			res = foo.emplace(*i);
			if (res.second == false) {
				auto tamp = i;
				i--;
				nums.erase(tamp);
			}
		}
		return foo.size();
	}
};
class Solution2 {
public:
	int removeDuplicates(std::vector<int>& nums) {
		auto a = 1;
		for (auto i = 1; i < nums.size(); ++i) {
			if (nums[i] != nums[i - 1]) {
				nums[a++] = nums[i];
			}
		}
		return nums.size() > a ? a : nums.size();
	}
};
int main()
{
	std::vector<int> v = {1, 2, 3, 4, 5, 4, 3, 2, 4, 5, 6, 7};
	sort(v.begin(), v.end());
	Solution2 so;
	std::cout << so.removeDuplicates(v) << std::endl;
	return 0;
}
