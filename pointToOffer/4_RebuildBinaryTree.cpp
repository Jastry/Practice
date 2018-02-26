#include <iostream>

struct BinaryTreeNode {
    int m_val;
    BinaryTreeNode * m_left;
    BinaryTreeNode * m_right;

    BinaryTreeNode(int x) : m_val(x), m_left(NULL), m_right(NULL) {}
};
typedef BinaryTreeNode Node;

class Solution {
public:
    Node * reConstructBinaryTree(std::vector<int> pre, std::vector<int> vin) {
        auto size = pre.size();
        if (size == 0)
            return NULL;

        auto root = new Node(pre[0])
        int rootIdx = 0;

        for (auto i = 0; i < size; ++i) {
            if (pre[0] == vin[i]) {
                rootIdx = i;
                break;
            }
        }

        std::vector<int> pre_left, in_left, pre_right, in_right;
        for (auto i = 0; i < rootIdx; ++i) {
            pre_left.push_back(pre[i+1]);
            in_left.push_back(vin[i]);
        }

        for (auto i = rootIdx + 1; i < size; ++i) {
            pre_right.push_back(pre[i]);
            in_right.push_back(vin[i]);
        }

        root->m_left = reConstructBinaryTree(pre_left, in_left);
        root->m_left = reConstructBinaryTree(pre_right, in_right);

        return root;
    }
};

int main()
{
	int a[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int b[] = { 4, 7, 2, 1, 5, 3, 8, 6 };
	std::vector<int> va(a, a + sizeof(a)/sizeof(int));
	std::vector<int> vb(b, b + sizeof(b) / sizeof(int));

	Solution3 so;
	BinaryTreeNode * root = so.reConstructBinaryTree(va, vb);
	return 0;
}
