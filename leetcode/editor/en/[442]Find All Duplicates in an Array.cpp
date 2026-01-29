//Given an integer array nums of length n where all the integers of nums are in 
//the range [1, n] and each integer appears at most twice, return an array of all 
//the integers that appears twice. 
//
// You must write an algorithm that runs in O(n) time and uses only constant 
//auxiliary space, excluding the space needed to store the output 
//
// 
// Example 1: 
// Input: nums = [4,3,2,7,8,2,3,1]
//Output: [2,3]
// 
// Example 2: 
// Input: nums = [1,1,2]
//Output: [1]
// 
// Example 3: 
// Input: nums = [1]
//Output: []
// 
// 
// Constraints: 
//
// 
// n == nums.length 
// 1 <= n <= 10⁵ 
// 1 <= nums[i] <= n 
// Each element in nums appears once or twice. 
// 
//
// Related TopicsArray | Hash Table | Sorting 
//
// 👍 11069, 👎 442bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // Input: nums = [4,3,2,7,8,2,3,1]
        //Output: [2,3]
        std::sort(nums.begin(),nums.end());
        std::vector<int> ret;
        for(int i=0,n=nums.size();i<n;++i){
            if(i>0 && nums[i]==nums[i-1]){
                ret.push_back(nums[i]);
            }
        }
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
