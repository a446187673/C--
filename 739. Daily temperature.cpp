#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<algorithm>

using namespace std;
//739. 每日温度 https://leetcode.cn/problems/daily-temperatures/
//单调栈
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(),0);
        stack<int> st;
        st.push(0);
        for (int i = 1; i < temperatures.size(); i++)
        {
            if(temperatures[i] <= temperatures[st.top()]) //当小于等于时，单调递增栈符合，推入元素
            {
                st.push(i);
            }
            else
            {
                while (!st.empty() && temperatures[i] > temperatures[st.top()]) //大于时收集该被大于数字前的元素下标差
                {
                    res[st.top()] = i - st.top();
                    st.pop();
                    
                }
                st.push(i); //收集后推入元素保持单调栈
            }
        }
        return res;
    }
};
int main()
{
    
    system("Pause");
}
