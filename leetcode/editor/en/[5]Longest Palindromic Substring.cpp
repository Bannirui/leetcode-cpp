//Given a string s, return the longest palindromic substring in s. 
//
// 
// Example 1: 
//
// 
//Input: s = "babad"
//Output: "bab"
//Explanation: "aba" is also a valid answer.
// 
//
// Example 2: 
//
// 
//Input: s = "cbbd"
//Output: "bb"
// 
//
// 
// Constraints: 
//
// 
// 1 <= s.length <= 1000 
// s consist of only digits and English letters. 
// 
//
// Related TopicsTwo Pointers | String | Dynamic Programming 
//
// 👍 32131, 👎 1977bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string longestPalindrome(string s) {
        //Input: s = "babad"
        //Output: "bab"
        //Explanation: "aba" is also a valid answer.
        int n=s.size();
        std::vector<std::vector<bool>> dp(n,std::vector<bool>(n,false));
        int l=0,len=0;
        // base
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(i>=j){
                    dp[i][j]=true;
                    if(j-i+1>len){
                        len=j-i+1;
                        l=i;
                    }
                }
            }
        }
        for(int i=n-1;i>=0;--i){
            for(int j=i+1;j<n;++j){
                    if(s[i]==s[j]){
                        dp[i][j]=dp[i+1][j-1];
                        if(dp[i][j]){
                            if(j-i+1>len){
                                len=j-i+1;
                                l=i;
                            }
                        }
                    }
            }
        }
        return s.substr(l,len);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
