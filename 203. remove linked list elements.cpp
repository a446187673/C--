#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//203. 移除链表元素 https://leetcode.cn/problems/remove-linked-list-elements/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(-99);
        dummy->next = head;
        ListNode* cur = dummy;
        ListNode* bf = cur;
        while(cur != nullptr)
        {
            if(cur->val == val)
            {
                bf->next = cur->next;
            }
            bf = cur;
            cur = cur->next;
        }
        return dummy->next;
    }
};
int main()
{
    
    system("Pause");
}
