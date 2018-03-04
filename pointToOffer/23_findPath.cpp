#include <iostream>

/* 记录一棵树从根到叶子结点的权值 */
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
	std::vector< std::vector<int> > FindPath(TreeNode* root, int expectNumber) {
		if (NULL == root)
			return res;
		tmp.push_back(root->val);
		if ((expectNumber - root->val) == 0 && root->left == NULL && root->right == NULL) {
			res.push_back(tmp);
		}
		FindPath(root->left, expectNumber - root->val);
		FindPath(root->right, expectNumber - root->val);
		if (tmp.size() != 0) {
			tmp.pop_back();
		}
		return res;
	}
private:
	std::vector< std::vector<int> > res;
	std::vector<int> tmp;
};
class Solution1 {
public:
	std::vector< std::vector<int> > FindPath(TreeNode* root,int expectNumber) {
		std::vector< std::vector<int> > res;
		if (root == NULL)	return res;
		std::stack<TreeNode*> s;
		TreeNode * cur = root;
		std::vector<int> tmp;
		while (cur || !s.empty()) {
			while (cur) {
				s.push(cur);
				tmp.push_back(cur->val);
				cur = cur->left;
			}
			TreeNode * top = s.top();
			s.pop();

			if (top->right) {
				cur = top->right;
			}
			else {
				res.push_back(tmp);
				tmp.pop_back();
			}
		}
		return res;
	}
};
#endif

