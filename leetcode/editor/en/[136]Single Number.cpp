//Given a non-empty array of integers nums, every element appears twice except 
//for one. Find that single one. 
//
// You must implement a solution with a linear runtime complexity and use only 
//constant extra space. 
//
// 
// Example 1: 
//
// 
// Input: nums = [2,2,1] 
// 
//
// Output: 1 
//
// Example 2: 
//
// 
// Input: nums = [4,1,2,1,2] 
// 
//
// Output: 4 
//
// Example 3: 
//
// 
// Input: nums = [1] 
// 
//
// Output: 1 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 3 * 10⁴ 
// -3 * 10⁴ <= nums[i] <= 3 * 10⁴ 
// Each element in the array appears twice except for one element which appears 
//only once. 
// 
//
// Related TopicsArray | Bit Manipulation 
//
// 👍 18479, 👎 879bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret=0;
        for(int& x:nums){ret^=x;}
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
