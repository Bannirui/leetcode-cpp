//Given the root of a binary tree and an integer targetSum, return true if the 
//tree has a root-to-leaf path such that adding up all the values along the path 
//equals targetSum. 
//
// A leaf is a node with no children. 
//
// 
// Example 1: 
// 
// 
//Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
//Output: true
//Explanation: The root-to-leaf path with the target sum is shown.
// 
//
// Example 2: 
// 
// 
//Input: root = [1,2,3], targetSum = 5
//Output: false
//Explanation: There are two root-to-leaf paths in the tree:
//(1 --> 2): The sum is 3.
//(1 --> 3): The sum is 4.
//There is no root-to-leaf path with sum = 5.
// 
//
// Example 3: 
//
// 
//Input: root = [], targetSum = 0
//Output: false
//Explanation: Since the tree is empty, there are no root-to-leaf paths.
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the tree is in the range [0, 5000]. 
// -1000 <= Node.val <= 1000 
// -1000 <= targetSum <= 1000 
// 
//
// Related TopicsTree | Depth-First Search | Breadth-First Search | Binary Tree 
//
//
// 👍 10566, 👎 1207bug 反馈 | 使用指南 | 更多配套插件 
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        // base
        if(!root){return false;}
        if(!root->left && !root->right){
            // leaf
            return root->val==targetSum;
        }
        return this->hasPathSum(root->left,targetSum-root->val)
            || this->hasPathSum(root->right,targetSum-root->val);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
