#include "BinaryTree.hpp"
#include <queue>

class Solution {
public:
    typedef BinaryNode<int> Node;
    bool IsCompleteTree(Node * root) {
        if (root == NULL)
            return true;

        Node * tmp = NULL;
        std::queue< Node* > q; //pNodeQueue
        q.push(root);
        while ( (tmp = q.front()) != nullptr) {
            q.push(tmp->_left);
            q.push(tmp->_right);
            q.pop();
        }

        while ( ! q.empty() ) {
            tmp = q.front();
            if ( tmp != NULL )
                return false;
            q.pop();
        }
        return true;
    }
};

int main()
{
    /*          a 树
     *                      1
     *                    /   \
     *                   2     3
     *                  / \                                          /                           
     *                 4   5 
     *                    / \
     *                   6   7
     */

    /*          b 树
                          1
                        /   \
                      /       \
                    2           5
                  /   \        / \
                3      4     6    7
              /  \    / \   /  \  | \
             8    9  11 20 #   #  #  #
    */
    int a[] = {1, 2, 3, 4, 5, '#', '#', '#', '#', 6, 7};
    int b[] = {1, 2, 3, 8, '#', '#', 9, '#', '#', 4, 11, '#', '#', 20, '#', '#',5, 6, '#', '#',7,'#', '#',};

	BinaryTree<int> ta(a, sizeof(a) / sizeof(a[0]), '#');
	BinaryTree<int> tb(b, sizeof(b) / sizeof(b[0]), '#');

    Solution so;

    std::cout << "a 树不是完全二叉树" << so.IsCompleteTree(ta.GetRoot()) << std::endl;
    std::cout << "b 树是完全二叉树" << so.IsCompleteTree(tb.GetRoot()) << std::endl;
    
    return 0;
}
