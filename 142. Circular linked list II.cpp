#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//142. 环形链表 II https://leetcode.cn/problems/linked-list-cycle-ii/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != nullptr && fast->next !=nullptr)
        {
            //快指针和慢指针重合时
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
            {
                //头节点指针和重合点一起出发
                ListNode* idx1 = head;
                ListNode* idx2 = fast;
                while(idx1 != idx2)
                {
                    idx1 = idx1->next;
                    idx2 = idx2->next;
                }
                //此时指向环的入口
                return idx1;
            }
        }
        return nullptr;
    }
};
int main()
{
    
    system("Pause");
}
