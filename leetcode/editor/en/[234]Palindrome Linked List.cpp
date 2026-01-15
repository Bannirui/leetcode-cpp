//Given the head of a singly linked list, return true if it is a palindrome or 
//false otherwise. 
//
// 
// Example 1: 
// 
// 
//Input: head = [1,2,2,1]
//Output: true
// 
//
// Example 2: 
// 
// 
//Input: head = [1,2]
//Output: false
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the list is in the range [1, 10⁵]. 
// 0 <= Node.val <= 9 
// 
//
// 
//Follow up: Could you do it in 
//O(n) time and 
//O(1) space?
//
// Related TopicsLinked List | Two Pointers | Stack | Recursion 
//
// 👍 18061, 👎 968bug 反馈 | 使用指南 | 更多配套插件 
//
//
//
//


#include "../../../stdc.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // [1,2,2,1]
        // [1,2,1]
        std::vector<int> nums;
        while(head){
            nums.push_back(head->val);
            head=head->next;
        }
        int lo=0,hi=nums.size()-1;
        while(lo<hi){
            if(nums[lo++]!=nums[hi--]){return false;}
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
