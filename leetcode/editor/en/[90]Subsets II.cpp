//Given an integer array nums that may contain duplicates, return all possible 
//subsets (the power set). 
//
// The solution set must not contain duplicate subsets. Return the solution in 
//any order. 
//
// 
// Example 1: 
// Input: nums = [1,2,2]
//Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
// 
// Example 2: 
// Input: nums = [0]
//Output: [[],[0]]
// 
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 10 
// -10 <= nums[i] <= 10 
// 
//
// Related TopicsArray | Backtracking | Bit Manipulation 
//
// 👍 10799, 👎 405bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::vector<std::vector<int>> paths;
        if(nums.empty()){return paths;}

        std::sort(nums.begin(),nums.end());
        std::vector<int> path;
        backTrack(nums,0,path,paths);
        return paths;
    }

    void backTrack(std::vector<int>& nums,int i,std::vector<int>& path,std::vector<std::vector<int>>& paths){
        int n;
        // base
        if((n=nums.size())==i){
            paths.push_back(path);
            return;
        }
        // pick or not
        path.push_back(nums[i]);
        backTrack(nums,i+1,path,paths);
        // recover
        path.pop_back();
        // 不选i的情况还有可能是重复
        while(i+1<n && nums[i]==nums[i+1]){++i;}
        backTrack(nums,i+1,path,paths);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
