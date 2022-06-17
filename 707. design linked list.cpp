#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//707. 设计链表 https://leetcode.cn/problems/design-linked-list/
class MyLinkedList {
public:
    
    struct ListNode
    {
        int val;
        ListNode* next;
        ListNode(int val)
        {
            this->val = val;
            this->next = nullptr;
        }
    };
    ListNode* dummy = nullptr;
    int size = 0;
    MyLinkedList() {
        dummy = new ListNode(-99);
    }
    ListNode* getnode(int index)
    {
        if(index == -1)
            return dummy;
        ListNode* cur = dummy;
        while (index >= 0)
        {
            cur = cur->next;
            index--;
        }
        return cur;
    }
    int get(int index) {
        if(index < 0 || index > size - 1)
            return -1;
        ListNode* cur = dummy->next;
        while (index > 0)
        {
            cur = cur->next;
            index--;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        ListNode* node = new ListNode(val);
        node->next = dummy->next;
        dummy->next = node;
        size++;
    }
    
    void addAtTail(int val) {
        ListNode* cur = getnode(size - 1);
        ListNode* node = new ListNode(val);
        cur->next = node;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index <= 0 )
            addAtHead(val);
        else if(index > size)
            return;
        else if(index == size)
            addAtTail(val);
        else
        {
            ListNode* bf = getnode(index - 1);
            ListNode* cur = bf->next;
            bf->next = new ListNode(val);
            bf->next->next = cur;
            size++;
        }
        
    }
    
    void deleteAtIndex(int index) {
        if (index >= size || index < 0) {
            return;
        }
        ListNode* bf = getnode(index-1);
        bf->next = bf->next->next;
        size--;
    }
};
int main()
{
    
    system("Pause");
}
