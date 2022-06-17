#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//24. 两两交换链表中的节点 https://leetcode.cn/problems/swap-nodes-in-pairs/

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr)
            return head;
        ListNode* dummy = new ListNode(-999);
        dummy->next = head;
        ListNode* cur = dummy;
        while (cur->next != nullptr && cur->next->next != nullptr)
        {
            ListNode* first = cur->next;
            ListNode* third = cur->next->next->next;

            cur->next = cur->next->next;
            cur->next->next = first;
            first->next = third;
            cur = cur->next->next;
        }
        return dummy->next;
    }
};
int main()
{
    
    system("Pause");
}
