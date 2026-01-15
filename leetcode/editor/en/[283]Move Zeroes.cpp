//Given an integer array nums, move all 0's to the end of it while maintaining 
//the relative order of the non-zero elements. 
//
// Note that you must do this in-place without making a copy of the array. 
//
// 
// Example 1: 
// Input: nums = [0,1,0,3,12]
//Output: [1,3,12,0,0]
// 
// Example 2: 
// Input: nums = [0]
//Output: [0]
// 
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 10⁴ 
// -2³¹ <= nums[i] <= 2³¹ - 1 
// 
//
// 
//Follow up: Could you minimize the total number of operations done?
//
// Related TopicsArray | Two Pointers 
//
// 👍 18957, 👎 569bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // Input: nums = [0,1,0,3,12]
        //Output: [1,3,12,0,0]
        // 相对有序
        // [0...i]放非0
        int i=0; // 下一个放的位置
        int j=0;
        int n=nums.size();
        while(j<n){
            if(nums[j]){
                std::swap(nums[i],nums[j]);
                ++i;
                ++j;
            }else{++j;}
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
