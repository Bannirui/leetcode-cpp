//Given a collection of numbers, nums, that might contain duplicates, return 
//all possible unique permutations in any order. 
//
// 
// Example 1: 
//
// 
//Input: nums = [1,1,2]
//Output:
//[[1,1,2],
// [1,2,1],
// [2,1,1]]
// 
//
// Example 2: 
//
// 
//Input: nums = [1,2,3]
//Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 8 
// -10 <= nums[i] <= 10 
// 
//
// Related TopicsArray | Backtracking | Sorting 
//
// 👍 9063, 👎 161bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::vector<std::vector<int>> ret;
        if(nums.empty()){return ret;}
        std::sort(nums.begin(), nums.end());
        int n=nums.size();
        std::vector<bool> visit(n,false);
        std::vector<int> path;
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
            if(i>0 && !visit[i-1] && nums[i]==nums[i-1]){continue;}
            if(!visit[i]){
                visit[i]=true;
                path.push_back(nums[i]);
                this->backTrack(nums,visit,path,paths);
                // 恢复现场
                path.pop_back();
                visit[i]=false;
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
