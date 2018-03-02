#include <iostream>

/* 顺时针打印矩阵 */
#if 0
class Solution {
public:
	std::vector<int> printMatrix( std::vector< std::vector< int > > matrix) {
		std::vector<int> res;
		int row = matrix.size();
		int col = matrix[0].size();
		//res.reserve(row * col);

		int left = 0, top = 0, right = col - 1, bottom = row - 1;
		while (left <= right && top <= bottom) {
			
			for (int i = left; i <= right; ++i) {
				res.push_back(matrix[top][i]);
			}

			for (int i = top + 1; i <= bottom; ++i) {
				res.push_back(matrix[i][right]);
			}

			if (top != bottom) {
				for (int i = right - 1; i >= left; --i) {
					res.push_back(matrix[bottom][i]);
				}
			}

			if (left != right) {
				for (int i = bottom - 1; i > top; --i) {
					res.push_back(matrix[i][left]);
				}
			}
			left++, right--, top++, bottom--;
		}
		return res;
	}
};

int main()
{
	std::vector< std::vector<int> > matrix = { { 1, 2, 3, 4 },
											   { 5, 6, 7, 8 },
											   { 9, 10, 11, 12},
											   { 13, 14, 15, 16} };
	Solution so;
	std::vector<int> res = so.printMatrix(matrix);

	return 0;
}
#endif

