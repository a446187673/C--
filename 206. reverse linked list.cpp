#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//206. 反转链表 https://leetcode.cn/problems/reverse-linked-list/
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* nxt;
        ListNode* bf = nullptr;
        while (cur != nullptr)
        {
            nxt = cur->next;
            cur->next = bf;
            bf = cur;
            cur = nxt;
        }
        return bf;
    }
};
int main()
{
    
    system("Pause");
}
