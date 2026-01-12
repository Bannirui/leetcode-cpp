//Given the roots of two binary trees p and q, write a function to check if 
//they are the same or not. 
//
// Two binary trees are considered the same if they are structurally identical, 
//and the nodes have the same value. 
//
// 
// Example 1: 
// 
// 
//Input: p = [1,2,3], q = [1,2,3]
//Output: true
// 
//
// Example 2: 
// 
// 
//Input: p = [1,2], q = [1,null,2]
//Output: false
// 
//
// Example 3: 
// 
// 
//Input: p = [1,2,1], q = [1,1,2]
//Output: false
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in both trees is in the range [0, 100]. 
// -10⁴ <= Node.val <= 10⁴ 
// 
//
// Related TopicsTree | Depth-First Search | Breadth-First Search | Binary Tree 
//
//
// 👍 12694, 👎 290bug 反馈 | 使用指南 | 更多配套插件 
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // base
        if(!p || !q) {return p==q;}
        return (p->val == q->val) && this->isSameTree(p->left,q->left) && this->isSameTree(p->right,q->right);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
