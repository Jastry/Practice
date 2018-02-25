#include <iostream>
#include <vector>

struct BinaryTreeNode {
    int m_val;
    BinaryTreeNode * m_left;
    BinaryTreeNode * m_right;

    BinaryTreeNode(int x) : m_val(x), m_left(NULL), m_right(NULL) {}
};

class Solution {
public:
    BinaryTreeNode * ConstructTree(std::vector<int> pre, std::vector<int> vin) {
        auto len = pre.size();
        if (len <= 0) {
            return NULL;
        }

        std::vector<int> pre_left, in_left, pre_right, in_right;
        auto root = new BinaryTreeNode(pre[0]);
        auto rootIndex = 0;
        for (auto i = 0; i < len; ++i) {
            if (pre[0] == vin[i]) {
                rootIndex = i;
                break;
            }
        }
        
        //Construct left tree
        for (auto i = 0; i < rootIndex; ++i) {
            //first is root
            pre_left.push_back(pre[i + 1]);
            in_left.push_back(vin[i]);
        }

        //Construct right tree
        for (auto i = rootIndex + 1; i < len; ++i) {
            pre_right.push_back(pre[i]);
            in_right.push_back(vin[i]);
        }

        root->m_left = ConstructTree(pre_left, in_left);
        root->m_right = ConstructTree(pre_right, in_right);

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
	BinaryTreeNode * root = so.ConstructTree(va, vb);

	return 0;
}
