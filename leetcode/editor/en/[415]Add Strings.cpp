//Given two non-negative integers, num1 and num2 represented as string, return 
//the sum of num1 and num2 as a string. 
//
// You must solve the problem without using any built-in library for handling 
//large integers (such as BigInteger). You must also not convert the inputs to 
//integers directly. 
//
// 
// Example 1: 
//
// 
//Input: num1 = "11", num2 = "123"
//Output: "134"
// 
//
// Example 2: 
//
// 
//Input: num1 = "456", num2 = "77"
//Output: "533"
// 
//
// Example 3: 
//
// 
//Input: num1 = "0", num2 = "0"
//Output: "0"
// 
//
// 
// Constraints: 
//
// 
// 1 <= num1.length, num2.length <= 10⁴ 
// num1 and num2 consist of only digits. 
// num1 and num2 don't have any leading zeros except for the zero itself. 
// 
//
// Related TopicsMath | String | Simulation 
//
// 👍 5402, 👎 829bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string addStrings(string num1, string num2) {
        //Input: num1 = "11", num2 = "123"
        //Output: "134"
        std::string ret;
        int carry=0;
        int i=num1.size()-1,j=num2.size()-1;
        while(i>=0||j>=0){
            int sum=(i>=0?(num1[i]-'0'):0)+(j>=0?(num2[j]-'0'):0)+carry;
            --i;
            --j;
            carry=sum/10;
            ret.insert(ret.begin(),(sum%10)+'0');
        }
        if(carry){ret.insert(ret.begin(),carry+'0');}
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
