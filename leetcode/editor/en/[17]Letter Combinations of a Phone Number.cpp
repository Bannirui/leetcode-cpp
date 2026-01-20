//Given a string containing digits from 2-9 inclusive, return all possible 
//letter combinations that the number could represent. Return the answer in any order. 
//
//
// A mapping of digits to letters (just like on the telephone buttons) is given 
//below. Note that 1 does not map to any letters. 
// 
// 
// Example 1: 
//
// 
//Input: digits = "23"
//Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// 
//
// Example 2: 
//
// 
//Input: digits = "2"
//Output: ["a","b","c"]
// 
//
// 
// Constraints: 
//
// 
// 1 <= digits.length <= 4 
// digits[i] is a digit in the range ['2', '9']. 
// 
//
// Related TopicsHash Table | String | Backtracking 
//
// 👍 20644, 👎 1119bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        std::unordered_map<char,std::vector<char>> map;
        // 2 abc
        // 3 def
        // 4 ghi
        // 5 jkl
        // 6 mno
        // 7 pqrs
        // 8 tuv
        // 9 wxyz
        map['2']={'a','b','c'};
        map['3']={'d','e','f'};
        map['4']={'g','h','i'};
        map['5']={'j','k','l'};
        map['6']={'m','n','o'};
        map['7']={'p','q','r','s'};
        map['8']={'t','u','v'};
        map['9']={'w','x','y','z'};
        std::string str;
        std::vector<std::string> strs;
        this->dfs(digits,0,map,str,strs);
        return strs;
    }

    void dfs(std::string digits, int i, std::unordered_map<char,std::vector<char>>& map, std::string& str, std::vector<std::string>& strs){
        // base
        int n=digits.size();
        if(i==n){
            std::string tmp(str);
            strs.push_back(tmp);
            return;
        }
        std::vector<char> chs=map[digits[i]];
        for(auto ch:chs){
            str.push_back(ch);
            this->dfs(digits,i+1,map,str,strs);
            str.pop_back();
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
