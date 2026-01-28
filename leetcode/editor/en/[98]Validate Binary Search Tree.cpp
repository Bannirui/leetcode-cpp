//Given the root of a binary tree, determine if it is a valid binary search 
//tree (BST). 
//
// A valid BST is defined as follows: 
//
// 
// The left subtree of a node contains only nodes with keys strictly less than 
//the node's key. 
// The right subtree of a node contains only nodes with keys strictly greater 
//than the node's key. 
// Both the left and right subtrees must also be binary search trees. 
// 
//
// 
// Example 1: 
// 
// 
//Input: root = [2,1,3]
//Output: true
// 
//
// Example 2: 
// 
// 
//Input: root = [5,1,4,null,null,3,6]
//Output: false
//Explanation: The root node's value is 5 but its right child's value is 4.
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the tree is in the range [1, 10⁴]. 
// -2³¹ <= Node.val <= 2³¹ - 1 
// 
//
// Related TopicsTree | Depth-First Search | Binary Search Tree | Binary Tree 
//
// 👍 18201, 👎 1442bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev{nullptr};
        bool flag{true};
        preOrder(root,prev,flag);
        return flag;
    }
private:
    void preOrder(TreeNode* root,TreeNode*& prev,bool& flag){
        // base
        if(!root){return;}
        preOrder(root->left,prev,flag);
        if(prev && prev->val>=root->val){flag=false;}
        prev=root;
        preOrder(root->right,prev,flag);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
