#include <iostream>

/* 判断一棵树是否为另一棵树的子树 */


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

class Solution {
private:
	bool IsSubTree(TreeNode * t1, TreeNode * t2) {
		if (t2 == NULL)
			return true;
		if (t1 == NULL)
			return false;
		if (t1->val != t2->val)
			return false;
		return IsSubTree(t1->left, t2->left) && IsSubTree(t1->right, t2->right);

	}
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		bool result = false;
		if (pRoot1 != NULL && pRoot2 != NULL) {

			if (pRoot1->val == pRoot2->val){
				result = IsSubTree(pRoot1->left, pRoot2->left) && IsSubTree(pRoot1->right, pRoot2->right);
			}
			if (!result)
				result = HasSubtree(pRoot1->left, pRoot2);
			if (!result)
				result = HasSubtree(pRoot1->right, pRoot2);
		}
		return result;
	}
};

