//Given the head of a singly linked list and two integers left and right where 
//left <= right, reverse the nodes of the list from position left to position 
//right, and return the reversed list. 
//
// 
// Example 1: 
// 
// 
//Input: head = [1,2,3,4,5], left = 2, right = 4
//Output: [1,4,3,2,5]
// 
//
// Example 2: 
//
// 
//Input: head = [5], left = 1, right = 1
//Output: [5]
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the list is n. 
// 1 <= n <= 500 
// -500 <= Node.val <= 500 
// 1 <= left <= right <= n 
// 
//
// 
//Follow up: Could you do it in one pass?
//
// Related TopicsLinked List 
//
// 👍 12790, 👎 775bug 反馈 | 使用指南 | 更多配套插件 
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        //Input: head = [1,2,3,4,5], left = 2, right = 4
        //Output: [1,4,3,2,5]
        // base
        if(left>=right){return head;}
        ListNode* dummy=new ListNode(-1,head);
        ListNode* prev=dummy;
        ListNode* p=prev;
        for(int i=0;i<left-1;++i){p=p->next;}
        ListNode* preTail=p;
        ListNode* midHead=p->next;
        p=prev;
        for(int i=0;i<right;++i){p=p->next;}
        ListNode* midTail=p;
        ListNode* postHead=p->next;
        preTail->next=nullptr;
        midTail->next=nullptr;

        ListNode* mid=reverse(midHead);
        preTail->next=mid;
        midHead->next=postHead;
        return dummy->next;
    }

private:
    ListNode* reverse(ListNode* head){
        if(head==nullptr || head->next==nullptr){return head;}
        ListNode* tail=reverse(head->next);
        head->next->next=head;
        head->next=nullptr;
        return tail;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
