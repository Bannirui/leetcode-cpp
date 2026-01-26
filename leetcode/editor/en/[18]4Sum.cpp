//Given an array nums of n integers, return an array of all the unique 
//quadruplets [nums[a], nums[b], nums[c], nums[d]] such that: 
//
// 
// 0 <= a, b, c, d < n 
// a, b, c, and d are distinct. 
// nums[a] + nums[b] + nums[c] + nums[d] == target 
// 
//
// You may return the answer in any order. 
//
// 
// Example 1: 
//
// 
//Input: nums = [1,0,-1,0,-2,2], target = 0
//Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
// 
//
// Example 2: 
//
// 
//Input: nums = [2,2,2,2,2], target = 8
//Output: [[2,2,2,2]]
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 200 
// -10⁹ <= nums[i] <= 10⁹ 
// -10⁹ <= target <= 10⁹ 
// 
//
// Related TopicsArray | Two Pointers | Sorting 
//
// 👍 12667, 👎 1526bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // 0 <= a, b, c, d < n
		// a, b, c, and d are distinct.
		// nums[a] + nums[b] + nums[c] + nums[d] == target
        int n=0;
        std::vector<std::vector<int>> ret;
        if((n=nums.size())<=3){return ret;}
        std::sort(nums.begin(),nums.end());
        // base
        long long minSum=(long long)nums[0]+nums[1]+nums[2]+nums[3];
        if(target<minSum){return ret;}
        long long maxSum=(long long)nums[n-1]+nums[n-2]+nums[n-3]+nums[n-4];
        if(target>maxSum){return ret;}
        for(int i=0;i<n;++i){
            if(i>0 && nums[i-1]==nums[i]){continue;}
            for(int j=i+1;j<n;++j){
                if(j>i+1 && nums[j-1]==nums[j]){continue;}
                int lo=j+1,hi=n-1;
                while(lo<hi){
                    long long sum=(long long)nums[i]+nums[j]+nums[lo]+nums[hi];
                    if(sum==target){
                        ret.push_back({nums[i],nums[j],nums[lo],nums[hi]});
                        ++lo;
                        --hi;
                        while(lo<hi && nums[lo]==nums[lo-1]){++lo;}
                        while(lo<hi && nums[hi]==nums[hi+1]){--hi;}
                    }else if(sum<target){
                        ++lo;
                    }else{
                        --hi;
                    }
                }
            }
        }
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
