//Given an integer array nums where the elements are sorted in ascending order, 
//convert it to a height-balanced binary search tree. 
//
// 
// Example 1: 
// 
// 
//Input: nums = [-10,-3,0,5,9]
//Output: [0,-3,9,-10,null,5]
//Explanation: [0,-10,5,null,-3,null,9] is also accepted:
//
// 
//
// Example 2: 
// 
// 
//Input: nums = [1,3]
//Output: [3,1]
//Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 10⁴ 
// -10⁴ <= nums[i] <= 10⁴ 
// nums is sorted in a strictly increasing order. 
// 
//
// Related TopicsArray | Divide and Conquer | Tree | Binary Search Tree | 
//Binary Tree 
//
// 👍 11788, 👎 635bug 反馈 | 使用指南 | 更多配套插件 
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        //Input: nums = [-10,-3,0,5,9]
        //Output: [0,-3,9,-10,null,5]
        //              0
        //            /    \
        //          -10
        return this->dfs(nums,0,nums.size()-1);
    }

private:
    TreeNode* dfs(std::vector<int>& nums, int lo, int hi){
        if(lo>hi){return nullptr;}
        if(lo==hi){return new TreeNode(nums[lo]);}
        int mid=lo+((hi-lo)>>1);
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=this->dfs(nums,lo,mid-1);
        root->right=this->dfs(nums,mid+1,hi);
        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
