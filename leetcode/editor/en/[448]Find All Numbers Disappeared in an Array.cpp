//Given an array nums of n integers where nums[i] is in the range [1, n], 
//return an array of all the integers in the range [1, n] that do not appear in nums. 
//
// 
// Example 1: 
// Input: nums = [4,3,2,7,8,2,3,1]
//Output: [5,6]
// 
// Example 2: 
// Input: nums = [1,1]
//Output: [2]
// 
// 
// Constraints: 
//
// 
// n == nums.length 
// 1 <= n <= 10⁵ 
// 1 <= nums[i] <= n 
// 
//
// 
// Follow up: Could you do it without extra space and in O(n) runtime? You may 
//assume the returned list does not count as extra space. 
//
// Related TopicsArray | Hash Table 
//
// 👍 10189, 👎 541bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // n integers nums[i]=[1, n],
        // Input: nums = [4,3,2,7,8,2,3,1]
        //Output: [5,6]
        std::vector<int> ret;
        int n=nums.size();
        int i=0;
        // mapping idx=0...n-1 val=1...n
        while(i<n){
            if(i+1==nums[i] || nums[i]==nums[nums[i]-1]){
                ++i;
                continue;
            }
            std::swap(nums[i],nums[nums[i]-1]);
        }
        for(i=0;i<n;i++){
            if(i+1!=nums[i]){ret.push_back(i+1);}
        }
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
