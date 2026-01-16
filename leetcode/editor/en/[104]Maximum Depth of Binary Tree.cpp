//Given the root of a binary tree, return its maximum depth. 
//
// A binary tree's maximum depth is the number of nodes along the longest path 
//from the root node down to the farthest leaf node. 
//
// 
// Example 1: 
// 
// 
//Input: root = [3,9,20,null,null,15,7]
//Output: 3
// 
//
// Example 2: 
//
// 
//Input: root = [1,null,2]
//Output: 2
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the tree is in the range [0, 10⁴]. 
// -100 <= Node.val <= 100 
// 
//
// Related TopicsTree | Depth-First Search | Breadth-First Search | Binary Tree 
//
//
// 👍 14099, 👎 282bug 反馈 | 使用指南 | 更多配套插件 
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
    int maxDepth(TreeNode* root) {
        //Input: root = [3,9,20,null,null,15,7]
        //Output: 3
        //                    3
        //                 /      \
        //                9        20
        //                        /   \
        //                       15    7
        // base
        if(!root){return 0;}
        int l=this->maxDepth(root->left);
        int r=this->maxDepth(root->right);
        return 1+std::max(l,r);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
