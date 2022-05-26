#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
#include<string>
#include<algorithm>

using namespace std;
//496. 下一个更大元素 I https://leetcode.cn/problems/next-greater-element-i/
//模拟
class Solution1 {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size; j++)
            {
                if(nums1[i] == nums2[j])
                {
                    for (int k = j; k < nums2.size(); k++)
                    {
                        if(nums2[k] > nums1[i])
                        {
                            res.push_back(nums2[k]); //找到
                            break;
                        }
                    }
                    if(res.size() < i+1)  //没找到
                        res.push_back(-1);
                    break;
                }
            }
            
        }
        return res;
    }
};  
//单调栈
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size(),-1);
        unordered_map<int,int> map;
        for (int i = 0; i < nums1.size(); i++)
            map.emplace(nums1[i],i);
        stack<int> st;
        st.push(0);
        for (int i = 1; i < nums2.size(); i++)
        {
            if(nums2[i] <= nums2[st.top()])
                st.push(i);
            else
            {
                while (!st.empty() && nums2[i] > nums2[st.top()])
                {
                    if(map.count(nums2[st.top()]) > 0) //map中如果有被大于的元素
                    {
                        int index = map[nums2[st.top()]]; //记录被大于元素的下标
                        res[index] = nums2[i];  //被大于元素前的最大数字为当前元素
                    }
                    st.pop();
                }
                st.push(i);
            }
        }
        return res;
        
    }
};
int main()
{
    
    system("Pause");
}
