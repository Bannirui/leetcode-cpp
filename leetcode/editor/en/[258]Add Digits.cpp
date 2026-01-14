//Given an integer num, repeatedly add all its digits until the result has only 
//one digit, and return it. 
//
// 
// Example 1: 
//
// 
//Input: num = 38
//Output: 2
//Explanation: The process is
//38 --> 3 + 8 --> 11
//11 --> 1 + 1 --> 2 
//Since 2 has only one digit, return it.
// 
//
// Example 2: 
//
// 
//Input: num = 0
//Output: 0
// 
//
// 
// Constraints: 
//
// 
// 0 <= num <= 2³¹ - 1 
// 
//
// 
// Follow up: Could you do it without any loop/recursion in O(1) runtime? 
//
// Related TopicsMath | Simulation | Number Theory 
//
// 👍 5391, 👎 1974bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int addDigits(int num) {
        // base
        if(num/10==0){return num;}
        int sum=0;
        while(num>0){
            sum+=(num%10);
            num/=10;
        }
        return this->addDigits(sum);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
