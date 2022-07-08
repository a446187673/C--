#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//面试题 02.07. 链表相交 https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //将两个链表和头结点靠右对齐
        ListNode* idxA = headA;
        ListNode* idxB = headB;
        int lenA = 0;
        int lenB = 0;
        while(idxA != nullptr)
        {
            idxA = idxA->next;
            lenA++;
        }
        while (idxB != nullptr)
        {
            idxB = idxB->next;
            lenB++;
        }
        idxA = headA;
        idxB = headB;

        if(lenA > lenB)
        {
            int gap = lenA - lenB;
            for (int i = 0; i < gap; i++)
            {
                idxA = idxA->next;
            }
        }
        else if(lenA < lenB)
        {
            int gap = lenB - lenA;
            for (int i = 0; i < gap; i++)
            {
                idxB = idxB->next;
            }
        }
        //求相等指针
        while(idxA != nullptr)
        {
            if(idxA == idxB)
            {
                return idxA;
            }
            idxA = idxA->next;
            idxB = idxB->next;
        }
        return nullptr;
    }
};
int main()
{
    
    system("Pause");
}
