#include <iostream>

/* 层序遍历二叉树 */
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
	std::vector<int> PrintFromTopToBottom(TreeNode* root) {
		std::vector<int> res;
		if (root == NULL)
			return res;

		std::queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			TreeNode * front = q.front();
			res.push_back(front->val);
			q.pop();
			if (front->left) {
				q.push(front->left);
			}
			if (front->right) {
				q.push(front->right);
			}
		}
		return res;
	}
};

