//Write a function to find the longest common prefix string amongst an array of 
//strings. 
//
// If there is no common prefix, return an empty string "". 
//
// 
// Example 1: 
//
// 
//Input: strs = ["flower","flow","flight"]
//Output: "fl"
// 
//
// Example 2: 
//
// 
//Input: strs = ["dog","racecar","car"]
//Output: ""
//Explanation: There is no common prefix among the input strings.
// 
//
// 
// Constraints: 
//
// 
// 1 <= strs.length <= 200 
// 0 <= strs[i].length <= 200 
// strs[i] consists of only lowercase English letters if it is non-empty. 
// 
//
// Related TopicsArray | String | Trie 
//
// 👍 20706, 👎 4875bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //Input: strs = ["flower","flow","flight"]
        //Output: "fl"
        int baseLen=0;
        std::string base;
        for(auto& s:strs){
            int curLen=s.size();
            if(curLen>baseLen){
                baseLen=curLen;
                base=s;
            }
        }
        int len=0;
        while(len<baseLen){
            for(auto& s:strs){
                if(s[len]!=base[len]) { return len==0?std::string(""):base.substr(0,len); }
            }
            len++;
        }
        return len==0?std::string(""):base.substr(0,len);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
