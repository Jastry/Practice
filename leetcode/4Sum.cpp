#include <iostream>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#if 1
class Solution {
public:
	std::vector< std::vector<int> > fourSum( std::vector< int >& nums, int target ) {
		std::vector< std::vector<int> > result;
		if (nums.size() < 4){
			return result;
		}
		sort(nums.begin(), nums.end());

		for (size_t i = 0; i < nums.size() - 3; ++i) {
			//跳过重复元素
			if (i > 0 && (nums[i] == nums[i - 1])) continue;
			std::vector< int > n(nums.begin() + i + 1, nums.end());
			std::vector< std::vector< int > > temp = threeSum(n, target - nums[i]);
			for (int j = 0; j < temp.size(); ++j) {
				temp[j].insert(temp[j].begin(), nums[i]);
				result.push_back(temp[j]);
			}
		}
		return result;
	}
private:
	std::vector< std::vector< int > >threeSum(std::vector< int > nums, int target)
	{
		std::vector< std::vector< int > > result;
		sort(nums.begin(), nums.end());
		int n = nums.size();

		for (int i = 0; i < n - 2; ++i) {
			//跳过相同元素
			if (i > 0 && (nums[i] == nums[i - 1])) continue;
			int a = nums[i];
			int low = i + 1;
			int high = n - 1;
			while (low < high) {
				int b = nums[high];
				int c = nums[low];
				int sum = a + b + c;
				if (sum == target) {
					std::vector< int > ret;
					ret.push_back(a);
					ret.push_back(b);
					ret.push_back(c);
					result.push_back(ret);
					//继续找三个元素求和为 target 的组合 
					while (low < n && (nums[low] == nums[low + 1])) low++;
					while (high > 0 && (nums[high] == nums[high - 1])) high--;
					low++;
					high--;
				}
				else if (sum > target) {
					while (high > 0 && (nums[high] == nums[high - 1])) high--;
					high--;
				}
				else {
					while (low < n && (nums[low] == nums[low + 1])) low++;
					low++;
				}
			}
		}
		return result;
	}
};

int main()
{
	//[1,0,-1,0,-2,2]
	//std::vector< int > v = { 1, -1, 2, -4, 3, -7, 8, 9, 0, -3, 5, 6, -11 };
	std::vector< int > v = { 1, 0, -1, -2, 2, 0 };
	Solution so;
	so.fourSum(v, 0);
	return 0;
}
