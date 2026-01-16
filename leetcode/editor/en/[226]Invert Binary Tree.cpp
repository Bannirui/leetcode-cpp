//Given the root of a binary tree, invert the tree, and return its root. 
//
// 
// Example 1: 
// 
// 
//Input: root = [4,2,7,1,3,6,9]
//Output: [4,7,2,9,6,3,1]
// 
//
// Example 2: 
// 
// 
//Input: root = [2,1,3]
//Output: [2,3,1]
// 
//
// Example 3: 
//
// 
//Input: root = []
//Output: []
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the tree is in the range [0, 100]. 
// -100 <= Node.val <= 100 
// 
//
// Related TopicsTree | Depth-First Search | Breadth-First Search | Binary Tree 
//
//
// 👍 15049, 👎 251bug 反馈 | 使用指南 | 更多配套插件 
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
    TreeNode* invertTree(TreeNode* root) {
        //Input: root = [4,2,7,1,3,6,9]
        //Output: [4,7,2,9,6,3,1]
        //              4
        //            /     \
        //           2       7
        //          /  \    /  \
        //         1    3  6    9
        //              4
        //            /     \
        //           7       2
        //          /  \    /  \
        //         9    6  3    1
        if(!root){return nullptr;}
        TreeNode* l=this->invertTree(root->left);
        TreeNode* r=this->invertTree(root->right);
        root->left=r;
        root->right=l;
        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
