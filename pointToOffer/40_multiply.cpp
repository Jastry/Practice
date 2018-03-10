#include <iostream>

/* 给定一个数组 A = 1, 2, 3, 4 求数组B[i] = B[i]=A[0]*A[1]*...*A[i-1] * A[i+1]*...*A[n-1] 除了 * A[i] */
#if 1
class Solution {
public:
	std::vector<int> multiply(const std::vector<int>& A) {
		std::vector<int> B;
		B.resize(A.size());

		B[0] = 1;
		for (int i = 1; i < A.size(); ++i) {
			B[i] = B[i - 1] * A[i - 1];
		}

		int temp = 1;
		for (int i = A.size() - 2; i >= 0; --i) {
			temp *= A[i + 1];
			B[i] *= temp;
		}
		return B;
	}
};

int main()
{
	Solution so;
	std::vector<int> a = { 1, 2, 3, 4 };
	std::vector<int> b = so.multiply(a);
	return 0;
}
#endif
