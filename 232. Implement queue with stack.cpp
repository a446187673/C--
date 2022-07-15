#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>

using namespace std;
//232. 用栈实现队列 https://leetcode.cn/problems/implement-queue-using-stacks/
class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    MyQueue() {
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        if (st2.empty() == true)
        {
            while (st1.empty() == false)
            {
                int tmp = st1.top();
                st1.pop();
                st2.push(tmp);
            }
        }
        int top = st2.top();
        st2.pop();
        return top;
    }
    
    int peek() {
        if (st2.empty() == true)
        {
            while (st1.empty() == false)
            {
                int tmp = st1.top();
                st1.pop();
                st2.push(tmp);
            }
        }
        return st2.top();
    }
    
    bool empty() {
        if(st1.empty() && st2.empty())
            return true;
        else
            return false;
    }
};
int main()
{
    
    system("Pause");
}
