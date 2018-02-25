#include "BinaryTree.hpp"

class Solution {
public:
    typedef BinaryNode<int> Node;
    bool IsBalanceTree( Node * root ) {
        int high = 0;
        return _IsBalanceTree(root, high);
    }

private:
    bool _IsBalanceTree(Node * root, int & high) { 
        if ( root == NULL ) {
            high = 0;
            return true;
        }

        int left_high = 0;
        if ( ! _IsBalanceTree(root->_left, left_high) ) {
            return false;
        }

        int right_high = 0;
        if ( ! _IsBalanceTree(root->_right, right_high) ) {
            return false;
        }

        int h = left_high > right_high ? left_high : right_high; 
        if ( abs( h ) > 1 )
            return false;
        return true;
    }
};

int main()
{
    int a[] = {1, 2, 5, 3, 4, 6, 7, '#', '#', 8, 9, 10, 11, '#', 20};

/*
                      1
                    /   \
                  /       \
                2           5
              /   \        / \
            3      4     6    7
          /  \    / \   /  \   | \
         #    #  8   9 10  11  #  20 
*/
	BinaryTree<int> t(a, sizeof(a) / sizeof(a[0]), '#');
    Solution so;
    std::cout << so.IsBalanceTree(t.GetRoot()) << std::endl;
    return 0;
}
