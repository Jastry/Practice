#include <iostream>

/* 判断一个序列是否是二叉搜索树的后序遍历结果 */
class Solution {
public:
	bool VerifySquenceOfBST(std::vector<int> sequence) {
		int size = sequence.size();
		if (size <= 0)
			return true;
		while (--size) {
			int i = 0;
			/* 右子树比根小 */
			while (sequence[i++] < sequence[size]);
			/* 左子树比根大 */
			while (sequence[i++] > sequence[size]);

			if (i < size)
				return false;
		}
		return true;
	}
};
