//Given two integer arrays preorder and inorder where preorder is the preorder 
//traversal of a binary tree and inorder is the inorder traversal of the same tree,
// construct and return the binary tree. 
//
// 
// Example 1: 
// 
// 
//Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
//Output: [3,9,20,null,null,15,7]
// 
//
// Example 2: 
//
// 
//Input: preorder = [-1], inorder = [-1]
//Output: [-1]
// 
//
// 
// Constraints: 
//
// 
// 1 <= preorder.length <= 3000 
// inorder.length == preorder.length 
// -3000 <= preorder[i], inorder[i] <= 3000 
// preorder and inorder consist of unique values. 
// Each value of inorder also appears in preorder. 
// preorder is guaranteed to be the preorder traversal of the tree. 
// inorder is guaranteed to be the inorder traversal of the tree. 
// 
//
// Related TopicsArray | Hash Table | Divide and Conquer | Tree | Binary Tree 
//
// 👍 16491, 👎 615bug 反馈 | 使用指南 | 更多配套插件 
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int m=preorder.size();
        int n=inorder.size();
        if(m!=n){return nullptr;}
        return dfs(preorder,0,m-1,inorder,0,n-1);
    }

private:
    TreeNode* dfs(std::vector<int>& preorder,int a,int b,std::vector<int>& inorder,int c,int d){
        // base
        if(a>b){return nullptr;}
        TreeNode* root=new TreeNode(preorder[a]);
        if(a==b){return root;}
        // a [a+1...x] [x+1...b]
        // [c...y-1] y [y+1...d]
        int y=search(inorder,c,d,preorder[a]);
        if(y==-1){return nullptr;}
        // x-(a+1)=y-1-c
        int x=y-1-c+a+1;
        root->left=dfs(preorder,a+1,x,inorder,c,y-1);
        root->right=dfs(preorder,x+1,b,inorder,y+1,d);
        return root;
    }

    int search(std::vector<int>& nums,int lo,int hi,int target){
        for(int i=lo;i<=hi;++i){
            if(target==nums[i]){return i;}
        }
        return -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
