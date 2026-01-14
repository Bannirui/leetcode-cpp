//Given an array nums containing n distinct numbers in the range [0, n], return 
//the only number in the range that is missing from the array. 
//
// 
// Example 1: 
//
// 
// Input: nums = [3,0,1] 
// 
//
// Output: 2 
//
// Explanation: 
//
// n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is 
//the missing number in the range since it does not appear in nums. 
//
// Example 2: 
//
// 
// Input: nums = [0,1] 
// 
//
// Output: 2 
//
// Explanation: 
//
// n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is 
//the missing number in the range since it does not appear in nums. 
//
// Example 3: 
//
// 
// Input: nums = [9,6,4,2,3,5,7,0,1] 
// 
//
// Output: 8 
//
// Explanation: 
//
// n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is 
//the missing number in the range since it does not appear in nums. 
//
// 
// 
// 
// 
// 
// 
// 
//
// 
// 
// 
// 
// 
// 
// 
//
// 
// 
// 
//
// 
//
// 
// Constraints: 
//
// 
// n == nums.length 
// 1 <= n <= 10⁴ 
// 0 <= nums[i] <= n 
// All the numbers of nums are unique. 
// 
//
// 
// Follow up: Could you implement a solution using only O(1) extra space 
//complexity and O(n) runtime complexity? 
//
// Related TopicsArray | Hash Table | Math | Binary Search | Bit Manipulation | 
//Sorting 
//
// 👍 13988, 👎 3458bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // 测试用例:[3,0,1]
        // 测试用例:[0,1]
        // 测试用例:[1,2]
        int i=0;
        int n=nums.size();
        while(i<n){
            if(nums[i]==n){++i;}
            else if(nums[i]==i){++i;}
            else{
                std::swap(nums[i],nums[nums[i]]);
            }
        }
        // find
        i=0;
        while(i<n){
            if(i!=nums[i]){return i;}
            ++i;
        }
        return n;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
