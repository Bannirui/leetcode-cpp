//Given an array nums of size n, return the majority element. 
//
// The majority element is the element that appears more than ⌊n / 2⌋ times. 
//You may assume that the majority element always exists in the array. 
//
// 
// Example 1: 
// Input: nums = [3,2,3]
//Output: 3
// 
// Example 2: 
// Input: nums = [2,2,1,1,1,2,2]
//Output: 2
// 
// 
// Constraints: 
//
// 
// n == nums.length 
// 1 <= n <= 5 * 10⁴ 
// -10⁹ <= nums[i] <= 10⁹ 
// The input is generated such that a majority element will exist in the array. 
//
// 
//
// 
//Follow-up: Could you solve the problem in linear time and in 
//O(1) space?
//
// Related TopicsArray | Hash Table | Divide and Conquer | Sorting | Counting 
//
// 👍 22269, 👎 792bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        // base
        if(n==1){return nums[0];}
        std::unordered_map<int,int> map;
        for(auto& x:nums){
            if(auto it=map.begin();it!=map.end()){
                if(++map[x]>(n>>1)){return x;}
            }else{
                map[x]=1;
            }
        }
        return -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
