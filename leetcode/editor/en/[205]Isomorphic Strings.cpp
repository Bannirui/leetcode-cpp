//Given two strings s and t, determine if they are isomorphic. 
//
// Two strings s and t are isomorphic if the characters in s can be replaced to 
//get t. 
//
// All occurrences of a character must be replaced with another character while 
//preserving the order of characters. No two characters may map to the same 
//character, but a character may map to itself. 
//
// 
// Example 1: 
//
// 
// Input: s = "egg", t = "add" 
// 
//
// Output: true 
//
// Explanation: 
//
// The strings s and t can be made identical by: 
//
// 
// Mapping 'e' to 'a'. 
// Mapping 'g' to 'd'. 
// 
//
// Example 2: 
//
// 
// Input: s = "foo", t = "bar" 
// 
//
// Output: false 
//
// Explanation: 
//
// The strings s and t can not be made identical as 'o' needs to be mapped to 
//both 'a' and 'r'. 
//
// Example 3: 
//
// 
// Input: s = "paper", t = "title"
// 
//
// Output: true 
//
// 
// Constraints: 
//
// 
// 1 <= s.length <= 5 * 10⁴ 
// t.length == s.length 
// s and t consist of any valid ascii character. 
// 
//
// Related TopicsHash Table | String 
//
// 👍 10312, 👎 2268bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // Input: s = "paper", t = "title"
        int m=s.size(),n=t.size();
        if(m!=n){return false;}
        std::unordered_map<char,char> s2t;
        std::unordered_map<char,char> t2s;
        for(int i=0;i<m;++i){
            char sCh=s[i];
            char tCh=t[i];
            if(auto it=s2t.find(sCh);it!=s2t.end()){
                if(s2t[sCh]!=tCh){return false;}
            }else{
                s2t[sCh]=tCh;
            }
            if(auto it=t2s.find(tCh);it!=t2s.end()){
                if(t2s[tCh]!=sCh){return false;}
            }else{
                t2s[tCh]=sCh;
            }
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
