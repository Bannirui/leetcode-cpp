//Given the root of a binary tree, return all root-to-leaf paths in any order. 
//
// A leaf is a node with no children. 
//
// 
// Example 1: 
// 
// 
//Input: root = [1,2,3,null,5]
//Output: ["1->2->5","1->3"]
// 
//
// Example 2: 
//
// 
//Input: root = [1]
//Output: ["1"]
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the tree is in the range [1, 100]. 
// -100 <= Node.val <= 100 
// 
//
// Related TopicsString | Backtracking | Tree | Depth-First Search | Binary 
//Tree 
//
// 👍 7156, 👎 341bug 反馈 | 使用指南 | 更多配套插件 
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
    vector<string> binaryTreePaths(TreeNode* root) {
        //Input: root = [1,2,3,null,5]
		//Output: ["1->2->5","1->3"]
        //      1
        //    /   \
        //   2     3
        //     \
        //      5
        // base
        std::vector<std::string> ret;
        if(!root){return ret;}
		std::vector<int> cur;
        this->dfs(root,cur,ret);
        return ret;
    }

    void dfs(const TreeNode* root,std::vector<int>& cur,std::vector<std::string>& ret){
        //      1
        //    /   \
        //   2     3
        //     \
        //      5
        // base
        if(!root){return;}
        cur.push_back(root->val);
        // indentify leaf
        if(!root->left && !root->right){
            // leaf node, collect the path
            std::string path=this->join(cur);
            ret.push_back(path);
        }else{
            this->dfs(root->left,cur,ret);
            this->dfs(root->right,cur,ret);
        }
        cur.pop_back();
    }

    std::string join(std::vector<int>& nums){
        std::ostringstream oss;
        for(size_t i=0,n=nums.size();i<n;++i){
            if(i>0){oss<<"->";}
            oss<<nums[i];
        }
        return oss.str();
    }
};
//leetcode submit region end(Prohibit modification and deletion)
