#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>

using namespace std;
//225. 用队列实现栈 https://leetcode.cn/problems/implement-stack-using-queues/
class MyStack {
public:
    queue<int> que1;
    queue<int> que2;
    MyStack() {

    }
    
    void push(int x) {
        que1.push(x);
    }
    
    int pop() {
        int size = que1.size();
        while (size > 1)
        {
            que2.push(que1.front());
            que1.pop();
            size--;
        }
        int res = que1.front();
        que1.pop();
        while (que2.empty() == false)
        {
            que1.push(que2.front());
            que2.pop();
        }
        return res;
        
    }
    
    int top() {
        int size = que1.size();
        while (size > 1)
        {
            que2.push(que1.front());
            que1.pop();
            size--;
        }
        int res = que1.front();
        que1.pop();
        que2.push(res);
        while (que2.empty() == false)
        {
            que1.push(que2.front());
            que2.pop();
        }
        return res;
    }
    
    bool empty() {
        if(que1.empty())
            return true;
        else
            return false;
    }
};
int main()
{
    
    system("Pause");
}
