//Given a binary tree, find its minimum depth. 
//
// The minimum depth is the number of nodes along the shortest path from the 
//root node down to the nearest leaf node. 
//
// Note: A leaf is a node with no children. 
//
// 
// Example 1: 
// 
// 
//Input: root = [3,9,20,null,null,15,7]
//Output: 2
// 
//
// Example 2: 
//
// 
//Input: root = [2,null,3,null,4,null,5,null,6]
//Output: 5
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the tree is in the range [0, 10⁵]. 
// -1000 <= Node.val <= 1000 
// 
//
// Related TopicsTree | Depth-First Search | Breadth-First Search | Binary Tree 
//
//
// 👍 7764, 👎 1360bug 反馈 | 使用指南 | 更多配套插件 
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
    int minDepth(TreeNode* root) {
        //Input: root = [3,9,20,null,null,15,7]
        //Output: 2
        //                3
        //             /      \
        //            9        20
        //                   /    \
        //                  15     7
        // base
        if(!root){return 0;}
        if(!root->left && !root->right){return 1;}
        int l=INT_MAX;
        int r=INT_MAX;
        if(root->left){
            l=this->minDepth(root->left);
        }
        if(root->right){
            r=this->minDepth(root->right);
        }
        return 1+std::min(l,r);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
