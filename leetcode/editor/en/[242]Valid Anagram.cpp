//Given two strings s and t, return true if t is an anagram of s, and false 
//otherwise. 
//
// 
// Example 1: 
//
// 
// Input: s = "anagram", t = "nagaram" 
// 
//
// Output: true 
//
// Example 2: 
//
// 
// Input: s = "rat", t = "car" 
// 
//
// Output: false 
//
// 
// Constraints: 
//
// 
// 1 <= s.length, t.length <= 5 * 10⁴ 
// s and t consist of lowercase English letters. 
// 
//
// 
// Follow up: What if the inputs contain Unicode characters? How would you 
//adapt your solution to such a case? 
//
// Related TopicsHash Table | String | Sorting 
//
// 👍 13955, 👎 462bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isAnagram(string s, string t) {
        // s and t consist of lowercase English letters.
        std::vector<int> cnt(26,0);
        for(auto& ch:s){
            ++cnt[ch-'a'];
        }
        for(auto& ch:t){
            if(--cnt[ch-'a']<0){return false;}
        }
        for(size_t i=0;i<26;++i){
            if(cnt[i]){return false;}
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
