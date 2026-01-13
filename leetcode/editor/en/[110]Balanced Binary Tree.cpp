//Given a binary tree, determine if it is height-balanced. 
//
// 
// Example 1: 
// 
// 
//Input: root = [3,9,20,null,null,15,7]
//Output: true
// 
//
// Example 2: 
// 
// 
//Input: root = [1,2,2,3,3,null,null,4,4]
//Output: false
// 
//
// Example 3: 
//
// 
//Input: root = []
//Output: true
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the tree is in the range [0, 5000]. 
// -10⁴ <= Node.val <= 10⁴ 
// 
//
// Related TopicsTree | Depth-First Search | Binary Tree 
//
// 👍 11822, 👎 820bug 反馈 | 使用指南 | 更多配套插件 
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
    int getHeight(TreeNode* root){
        // base
        if(!root){return 0;}
        int l=this->getHeight(root->left);
        int h=this->getHeight(root->right);
        return (l>h?l:h)+1;
    }
    bool isBalanced(TreeNode* root) {
        // base
        if(!root){return true;}
        int lHeight=this->getHeight(root->left);
        int rHeight=this->getHeight(root->right);
        return (lHeight-rHeight<=1)&&(rHeight-lHeight<=1)
               &&this->isBalanced(root->left)
                &&this->isBalanced(root->right);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
