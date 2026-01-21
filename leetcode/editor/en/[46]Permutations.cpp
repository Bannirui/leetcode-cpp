//Given an array nums of distinct integers, return all the possible 
//permutations. You can return the answer in any order. 
//
// 
// Example 1: 
// Input: nums = [1,2,3]
//Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// 
// Example 2: 
// Input: nums = [0,1]
//Output: [[0,1],[1,0]]
// 
// Example 3: 
// Input: nums = [1]
//Output: [[1]]
// 
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 6 
// -10 <= nums[i] <= 10 
// All the integers of nums are unique. 
// 
//
// Related TopicsArray | Backtracking 
//
// 👍 20641, 👎 379bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<std::vector<int>> ret;
        if(nums.empty()){return ret;}
        std::vector<int> path;
        int n=nums.size();
        std::vector<bool> visit(n,false);
        this->backTrack(nums,visit,path,ret);
        return ret;
    }

    void backTrack(std::vector<int>& nums,std::vector<bool>& visit,std::vector<int>& path,std::vector<std::vector<int>>& paths){
        // base
        if(path.size()==nums.size()){
            paths.push_back(path);
            return;
        }
        for(int i=0,n=nums.size();i<n;++i){
            if(visit[i]){continue;}
            visit[i]=true;
            path.push_back(nums[i]);
            this->backTrack(nums,visit,path,paths);
            // 恢复现场
            path.pop_back();
            visit[i]=false;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
