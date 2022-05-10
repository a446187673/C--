#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//406. 根据身高重建队列 https://leetcode.cn/problems/queue-reconstruction-by-height/
//思路 1.先按身高从高到低排序
//2.然后依次根据前面有几个身高大于等于自身的人插入（由于身高从高到低，所以很容易插入）
class Solution {
public:
    static bool cmp(const vector<int>& a,const vector<int>& b)
    {
        if(a[0] == b[0])
            return a[1]<b[1];
        else
            return a[0]>b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),cmp);
        vector<vector<int>> res;
        
        for(vector<int> man : people)
        {
            int number = man[1];
            res.emplace(res.begin()+number,man); //每次只需要注意man的第二个数字是多少，就向后多少位
        }
        return res;

    }
};
int main()
{
    Solution s;
    vector<vector<int>> res{{7,0},{7,1},{6,1}};
    vector<vector<int>> r = s.reconstructQueue(res);
    for(vector<int> i : r)
        cout<<i[0]<<endl;
    
    system("Pause");
}
