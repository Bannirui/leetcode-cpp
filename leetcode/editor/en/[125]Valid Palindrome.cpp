//A phrase is a palindrome if, after converting all uppercase letters into 
//lowercase letters and removing all non-alphanumeric characters, it reads the same 
//forward and backward. Alphanumeric characters include letters and numbers. 
//
// Given a string s, return true if it is a palindrome, or false otherwise. 
//
// 
// Example 1: 
//
// 
//Input: s = "A man, a plan, a canal: Panama"
//Output: true
//Explanation: "amanaplanacanalpanama" is a palindrome.
// 
//
// Example 2: 
//
// 
//Input: s = "race a car"
//Output: false
//Explanation: "raceacar" is not a palindrome.
// 
//
// Example 3: 
//
// 
//Input: s = " "
//Output: true
//Explanation: s is an empty string "" after removing non-alphanumeric 
//characters.
//Since an empty string reads the same forward and backward, it is a palindrome.
//
// 
//
// 
// Constraints: 
//
// 
// 1 <= s.length <= 2 * 10⁵ 
// s consists only of printable ASCII characters. 
// 
//
// Related TopicsTwo Pointers | String 
//
// 👍 11214, 👎 8616bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isAlphanumeric(const char& ch){
        return isLower(ch) || isUpper(ch) || isNumber(ch);
    }
    bool isLower(const char& ch){
        return ch>='a' && ch<='z';
    }
    bool isUpper(const char& ch){
        return ch>='A' && ch<='Z';
    }
    bool isNumber(const char& ch){
        return ch>='0' && ch<='9';
    }
    bool isPalindrome(string s) {
        //Input: s = "A man, a plan, a canal: Panama"
        //Output: true
        //Explanation: "amanaplanacanalpanama" is a palindrome.
         if(s.empty()) {return true;}
         int len=s.size();
         int i=0,j=len-1;
         while(i<j){
             while(i<j && !this->isAlphanumeric(s[i])){i++;}
             while(i<j && !this->isAlphanumeric(s[j])){j--;}
             // both are not space
             char ch1=s[i],ch2=s[j];
             if(ch1==ch2){
                 i++;
                 j--;
                 continue;
             }
             if(isNumber(ch1)){
                 return false;
             }else{
                 if(isNumber(ch2)){return false;}
                 else{
                     if(isLower(ch1)){
                         if(isLower(ch2)){
                             if(ch1!=ch2){return false;}
                         }
                         else{
                             if((ch1-'a')!=(ch2-'A')){return false;}
                         }
                     }else{
                         if(isUpper(ch2)){
                             if(ch1!=ch2){return false;}
                         }
                         else{
                             if((ch1-'A')!=(ch2-'a')){return false;}
                         }
                     }
                 }
             }
             i++;
             j--;
         }
         return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
