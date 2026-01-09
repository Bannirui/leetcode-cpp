//Given a string s containing just the characters '(', ')', '{', '}', '[' and ']
//', determine if the input string is valid. 
//
// An input string is valid if: 
//
// 
// Open brackets must be closed by the same type of brackets. 
// Open brackets must be closed in the correct order. 
// Every close bracket has a corresponding open bracket of the same type. 
// 
//
// 
// Example 1: 
//
// 
// Input: s = "()" 
// 
//
// Output: true 
//
// Example 2: 
//
// 
// Input: s = "()[]{}"
// 
//
// Output: true 
//
// Example 3: 
//
// 
// Input: s = "(]" 
// 
//
// Output: false 
//
// Example 4: 
//
// 
// Input: s = "([])" 
// 
//
// Output: true 
//
// Example 5: 
//
// 
// Input: s = "([)]" 
// 
//
// Output: false 
//
// 
// Constraints: 
//
// 
// 1 <= s.length <= 10⁴ 
// s consists of parentheses only '()[]{}'. 
// 
//
// Related TopicsString | Stack 
//
// 👍 27242, 👎 1975bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isValid(string s) {
        // Input: s = "()[]{}"
        //
        //
        // Output: true
        std::unordered_map<char,char> map{{'}','{'},{']','['},{')','('}};
        std::stack<char> stack;
        for(auto c=s.cbegin();c!=s.cend();c++){
            if(auto o=map.find(*c);o!=map.end()){
                if(stack.empty()) { return false; }
                if(map[*c]!=stack.top()) { return false; }
                stack.pop();
            }else{
                stack.push(*c);
            }
        }
        return stack.empty();
    }
};
//leetcode submit region end(Prohibit modification and deletion)
