//Given the head of a sorted linked list, delete all duplicates such that each 
//element appears only once. Return the linked list sorted as well. 
//
// 
// Example 1: 
// 
// 
//Input: head = [1,1,2]
//Output: [1,2]
// 
//
// Example 2: 
// 
// 
//Input: head = [1,1,2,3,3]
//Output: [1,2,3]
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the list is in the range [0, 300]. 
// -100 <= Node.val <= 100 
// The list is guaranteed to be sorted in ascending order. 
// 
//
// Related TopicsLinked List 
//
// 👍 9691, 👎 357bug 反馈 | 使用指南 | 更多配套插件 
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
    ListNode* deleteDuplicates(ListNode* head) {
        //Input: head = [1,1,2,3,3]
        //Output: [1,2,3]
        ListNode* p=head;
        while(p){
            ListNode* cur=p;
            while(cur && cur->val==p->val){
                cur=cur->next;
            }
            p->next=cur;
            p=cur;
        }
        return head;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
