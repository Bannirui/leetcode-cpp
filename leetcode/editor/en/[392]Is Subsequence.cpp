//Given two strings s and t, return true if s is a subsequence of t, or false 
//otherwise. 
//
// A subsequence of a string is a new string that is formed from the original 
//string by deleting some (can be none) of the characters without disturbing the 
//relative positions of the remaining characters. (i.e., "ace" is a subsequence of 
//"abcde" while "aec" is not). 
//
// 
// Example 1: 
// Input: s = "abc", t = "ahbgdc"
//Output: true
// 
// Example 2: 
// Input: s = "axc", t = "ahbgdc"
//Output: false
// 
// 
// Constraints: 
//
// 
// 0 <= s.length <= 100 
// 0 <= t.length <= 10⁴ 
// s and t consist only of lowercase English letters. 
// 
//
// 
//Follow up: Suppose there are lots of incoming 
//s, say 
//s1, s2, ..., sk where 
//k >= 10⁹, and you want to check one by one to see if 
//t has its subsequence. In this scenario, how would you change your code?
//
// Related TopicsTwo Pointers | String | Dynamic Programming 
//
// 👍 10671, 👎 612bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isSubsequence(string s, string t) {
        // Input: s = "abc", t = "ahbgdc"
        //Output: true
        int m=s.size(),n=t.size();
        if(m==0){return true;}
        if(n==0){return false;}
        // dp[i][j] s的前i个 t的前j个 true or false
        std::vector<std::vector<bool>> dp(m+1,std::vector<bool>(n+1,false));
        // base
        for(int j=0;j<n;++j){dp[0][j]=true;}
        for(int i=1;i<m;++i){dp[i][0]=false;}
        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j){
                // s[0...i-2 i-1]
                // t[0...j-2 j-1]
                dp[i][j]=dp[i][j-1] || (s[i-1]==t[j-1] && dp[i-1][j-1]);
            }
        }
        return dp[m][n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
