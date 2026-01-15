//You are given a sorted unique integer array nums. 
//
// A range [a,b] is the set of all integers from a to b (inclusive). 
//
// Return the smallest sorted list of ranges that cover all the numbers in the 
//array exactly. That is, each element of nums is covered by exactly one of the 
//ranges, and there is no integer x such that x is in one of the ranges but not in 
//nums. 
//
// Each range [a,b] in the list should be output as: 
//
// 
// "a->b" if a != b 
// "a" if a == b 
// 
//
// 
// Example 1: 
//
// 
//Input: nums = [0,1,2,4,5,7]
//Output: ["0->2","4->5","7"]
//Explanation: The ranges are:
//[0,2] --> "0->2"
//[4,5] --> "4->5"
//[7,7] --> "7"
// 
//
// Example 2: 
//
// 
//Input: nums = [0,2,3,4,6,8,9]
//Output: ["0","2->4","6","8->9"]
//Explanation: The ranges are:
//[0,0] --> "0"
//[2,4] --> "2->4"
//[6,6] --> "6"
//[8,9] --> "8->9"
// 
//
// 
// Constraints: 
//
// 
// 0 <= nums.length <= 20 
// -2³¹ <= nums[i] <= 2³¹ - 1 
// All the values of nums are unique. 
// nums is sorted in ascending order. 
// 
//
// Related TopicsArray 
//
// 👍 4480, 👎 2365bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        //Input: nums = [0,1,2,4,5,7]
        //Output: ["0->2","4->5","7"]
        std::vector<std::string> ret;
        int i=0;
        int n=nums.size();
        while(i<n) {
            int j=i;
            while(j<n) {
                if(j==i) {++j;}
                else {
                    if(nums[j]==nums[j-1]+1) {++j;}
                    else {break;}
                }
            }
            // 不连续的下一段
            // [i...j-1]
            std::string s;
            if(i==j-1){
                s.append(std::to_string(nums[i]));
            }else{
                s.append(std::to_string(nums[i]));
                s.append("->");
                s.append(std::to_string(nums[j-1]));
            }
            ret.push_back(s);
            i=j;
        }
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
