#include <iostream>

/* 将二查搜索数转换为双向链表 */
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
	TreeNode * Convert(TreeNode* pRootOfTree)
	{
		if (pRootOfTree == NULL)    return NULL;
		TreeNode * cur = pRootOfTree;
		TreeNode * pre = NULL;
		TreeNode * res = NULL;
		std::stack<TreeNode *> s;
		bool isRoot = true;
		while (cur || !s.empty()) {
			while (cur) {
				s.push(cur);
				cur = cur->left;
			}
			TreeNode * top = s.top();
			s.pop();
			if (isRoot) {
				res = top;
				pre = res;
				isRoot = false;
			}
			else {
				pre->right = top;
				top->left = pre;
				pre = top;
			}
			cur = top->right;
		}
		return res;
	}
};
