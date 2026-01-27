//Given the root of a binary tree, return the bottom-up level order traversal 
//of its nodes' values. (i.e., from left to right, level by level from leaf to root)
//. 
//
// 
// Example 1: 
// 
// 
//Input: root = [3,9,20,null,null,15,7]
//Output: [[15,7],[9,20],[3]]
// 
//
// Example 2: 
//
// 
//Input: root = [1]
//Output: [[1]]
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
// The number of nodes in the tree is in the range [0, 2000]. 
// -1000 <= Node.val <= 1000 
// 
//
// Related TopicsTree | Breadth-First Search | Binary Tree 
//
// 👍 5134, 👎 333bug 反馈 | 使用指南 | 更多配套插件 
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        //Input: root = [3,9,20,null,null,15,7]
        //Output: [[15,7],[9,20],[3]]
        //               3
        //             /   \
        //            9     20
        //                 /   \
        //                15    7
        std::vector<std::vector<int>> ret;
        if(root==nullptr){return ret;}
        std::queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            std::vector<int> tmp;
            for(int i=0;i<n;++i){
                TreeNode* cur=q.front();
                q.pop();
                tmp.push_back(cur->val);
                if(cur->left){q.push(cur->left);}
                if(cur->right){q.push(cur->right);}
            }
            ret.insert(ret.begin(),tmp);
        }
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
