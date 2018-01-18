/* Container With Most Water */

/**********************************************************************************
*
* Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
* n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
*
* Find two lines, which together with x-axis forms a container, such that the container contains the most water.
*
* Note: You may not slant the container.
*
*
**********************************************************************************/
#include <iostream>
#include <vector>

class Solution {
public:
	int maxArea(std::vector<int>& height) {
		int left = 0;
		int right = height.size() - 1;
		int maxArea = 0;
		while (left < right) {
			int area = (right - left) * (height[left] > height[right] ? height[right] : height[left]);
			maxArea = maxArea > area ? maxArea : area;

			if (height[left] < height[right]) {
				do {
					left++;
				} while (left < right && height[left - 1] >= height[left]);
			}
			else {
				do {
					right--;
				} while (left < right && height[right + 1] >= height[right]);
			}
		}
		return maxArea;
	}
};

int main()
{
	std::vector<int> v = {2, 4, 3, 5 ,6 ,9, 7, 4};
	Solution so;
	std::cout << so.maxArea(v) << std::endl;
	return 0;
}
