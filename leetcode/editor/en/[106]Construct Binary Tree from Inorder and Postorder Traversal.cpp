//Given two integer arrays inorder and postorder where inorder is the inorder 
//traversal of a binary tree and postorder is the postorder traversal of the same 
//tree, construct and return the binary tree. 
//
// 
// Example 1: 
// 
// 
//Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
//Output: [3,9,20,null,null,15,7]
// 
//
// Example 2: 
//
// 
//Input: inorder = [-1], postorder = [-1]
//Output: [-1]
// 
//
// 
// Constraints: 
//
// 
// 1 <= inorder.length <= 3000 
// postorder.length == inorder.length 
// -3000 <= inorder[i], postorder[i] <= 3000 
// inorder and postorder consist of unique values. 
// Each value of postorder also appears in inorder. 
// inorder is guaranteed to be the inorder traversal of the tree. 
// postorder is guaranteed to be the postorder traversal of the tree. 
// 
//
// Related TopicsArray | Hash Table | Divide and Conquer | Tree | Binary Tree 
//
// 👍 8628, 👎 154bug 反馈 | 使用指南 | 更多配套插件 
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
        //Output: [3,9,20,null,null,15,7]
        int m=inorder.size();
        int n=postorder.size();
        if(m!=n){return nullptr;}
        return dfs(inorder,0,m-1,postorder,0,n-1);
    }

    TreeNode* dfs(std::vector<int>& inorder,int i,int j,std::vector<int>& postorder,int x,int y){
        // base
        if(i>j){return nullptr;}
        if(i==j){return new TreeNode(inorder[i]);}
        TreeNode* ret = new TreeNode(postorder[y]);
        // [i...k) k (k...j]
        int k=searchIndex(inorder,i,j,postorder[y]);
        if(k==-1){return nullptr;}
        // [x...z] (z...y) y
        int z=x+(k-1-i);
        ret->left=dfs(inorder,i,k-1,postorder,x,z);
        ret->right=dfs(inorder,k+1,j,postorder,z+1,y-1);
        return ret;
    }
    int searchIndex(std::vector<int>& nums, int i, int j, int val){
        for(int k=i;k<=j;++k){
            if(nums[k]==val){return k;}
        }
        return -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
