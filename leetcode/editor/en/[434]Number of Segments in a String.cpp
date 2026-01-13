//Given a string s, return the number of segments in the string. 
//
// A segment is defined to be a contiguous sequence of non-space characters. 
//
// 
// Example 1: 
//
// 
//Input: s = "Hello, my name is John"
//Output: 5
//Explanation: The five segments are ["Hello,", "my", "name", "is", "John"]
// 
//
// Example 2: 
//
// 
//Input: s = "Hello"
//Output: 1
// 
//
// 
// Constraints: 
//
// 
// 0 <= s.length <= 300 
// s consists of lowercase and uppercase English letters, digits, or one of the 
//following characters "!@#$%^&*()_+-=',.:". 
// The only space character in s is ' '. 
// 
//
// Related TopicsString 
//
// 👍 893, 👎 1331bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countSegments(string s) {
        //Input: s = "Hello, my name is John"
        //Output: 5
        //Explanation: The five segments are ["Hello,", "my", "name", "is", "John"]
        int ret=0;
        int i=0;
        int len=s.size();
        while(i<len){
            while(i<len&&s[i]==' '){++i;}
            // i non-space or bound
            int j=i;
            while(j<len&&s[j]!=' '){++j;}
            // j space or bound
            if(i==j){break;}
            ++ret;
            i=j;
        }
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
