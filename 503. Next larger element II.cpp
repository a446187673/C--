#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<algorithm>

using namespace std;
//503. 下一个更大元素 II https://leetcode.cn/problems/next-greater-element-ii/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(),-1);
        stack<int> st;
        st.push(0);
        for (int i = 1; i < nums.size()*2; i++)
        {
            if(nums[i % nums.size()] <= nums[st.top()])
                st.push(i % nums.size());
            else
            {
                while (!st.empty() && nums[i % nums.size()] > nums[st.top()]) //i % nums.size()作为下标模拟走两遍的nums
                {
                    res[st.top()] = nums[i % nums.size()];
                    st.pop();
                }
                st.push(i % nums.size());
            }
        }
        return res;
    }
};
int main()
{
    
    system("Pause");
}
