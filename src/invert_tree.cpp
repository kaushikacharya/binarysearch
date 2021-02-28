/**
* Problem: Invert Tree
* URL: https://binarysearch.com/problems/Invert-Tree
* Date: Feb 27, 2021
*
* Algorithm:
*   Post-order DFS traversal.
*   Solve first for left and right subtrees and then swap left and right subtree's root.
*
* Time complexity: O(n)
* Space complexity: O(n)
*
*/

#include <invert_tree.hpp>

using namespace std;

Tree* solve(Tree* root){
    if (root == nullptr){
        // cout << "nullptr" << endl;
        return root;
    }

    /**
    cout << "current root node: " << root->val << endl;
    if (root->left == nullptr){
        cout << "left of root node: nullptr" << endl;
    }
    else {
        cout << "left of root node: " << root->left->val << endl;
    }
    if (root->right == nullptr){
        cout << "right of root node: nullptr" << endl;
    }
    else {
        cout << "right of root node: " << root->right->val << endl;
    }
    */

    // a) invert the left and right subtrees
    // b) assign the inverted left subtree as right child of root and vice-versa
    Tree* invertedLeftNode = solve(root->right);
    Tree* invertedRightNode = solve(root->left);

    root->right = invertedRightNode;
    root->left = invertedLeftNode;


    return root;
}
