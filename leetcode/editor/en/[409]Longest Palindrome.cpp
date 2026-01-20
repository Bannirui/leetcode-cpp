//Given a string s which consists of lowercase or uppercase letters, return the 
//length of the longest palindrome that can be built with those letters. 
//
// Letters are case sensitive, for example, "Aa" is not considered a palindrome.
// 
//
// 
// Example 1: 
//
// 
//Input: s = "abccccdd"
//Output: 7
//Explanation: One longest palindrome that can be built is "dccaccd", whose 
//length is 7.
// 
//
// Example 2: 
//
// 
//Input: s = "a"
//Output: 1
//Explanation: The longest palindrome that can be built is "a", whose length is 
//1.
// 
//
// 
// Constraints: 
//
// 
// 1 <= s.length <= 2000 
// s consists of lowercase and/or uppercase English letters only. 
// 
//
// Related TopicsHash Table | String | Greedy 
//
// 👍 6307, 👎 443bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestPalindrome(string s) {
        //Input: s = "abccccdd"
        //Output: 7
        //Explanation: One longest palindrome that can be built is "dccaccd", whose
		// s consists of lowercase and/or uppercase English letters only.
        std::vector<int> lowerCnt(26,0);
        std::vector<int> upperCnt(26,0);
        for(int i=0,n=s.size();i<n;++i){
            char ch=s[i];
            if('a'<=ch && ch<='z'){++lowerCnt[ch-'a'];}
            else{++upperCnt[ch-'A'];}
        }
        int ret=0;
        bool oddRemain=false;
        for(int i=0;i<26;++i){
            int num=lowerCnt[i];
            if((num&1)==0){
                ret+=num;
            }else{
                ret+=(num-1);
                if(!oddRemain){oddRemain=true;}
            }
        }
        for(int i=0;i<26;++i){
            int num=upperCnt[i];
            if((num&1)==0){
                ret+=num;
            }else{
                ret+=(num-1);
                if(!oddRemain){oddRemain=true;}
            }
        }
        if(oddRemain){++ret;}
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
