#include <iostream>

/* 二叉树的镜像 */
#if 1

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	void Mirror(TreeNode *r) {
		if (r == NULL)
			return;
		TreeNode * tmp = r->left;
		r->left = r->right;
		r->right = tmp;
		Mirror(r->left);
		Mirror(r->right);
	}
};

#endif

