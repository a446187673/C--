#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//134. 加油站 https://leetcode-cn.com/problems/gas-station/
//偏暴力解法
//思路 1.如果当前gas总量小于cost总量，说明肯定走不完
//2.如果大于等于，那么就从0号加油站开始计算rest = gas[i]-cost[i]，确保每次rest=>0
//3.如果rest<0，说明不能从0出发，那么从后向前遍历，直到找到
class Solution {
public:
    int OLDcanCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0; //1.确保总油量足够
        for(int i : gas)
            sum+=i;
        for(int i : cost)
        {
            sum-=i;
            if(sum<0)
                return -1;
        }
        
        
        for (int i = gas.size()-1; i >= 0; i--)
        {
            int rest = 0;
            int beginindex = i;
            for (int j = 0; j < gas.size(); j++)
            {
                if (beginindex == gas.size()) //环路
                    beginindex = 0;
                
                rest += gas[beginindex]-cost[beginindex];
                if(rest<0)
                    break;
                beginindex++;
            }
            if(rest >= 0)
            {
                if (beginindex == gas.size()) //环路
                    beginindex = 0;
                return beginindex;
            }
        }
        return -1;
    }
};

//贪心算法
//思路 1.确定是否能跑完全程
//2. 如果可以跑完全程，那么从0开始遍历gas数组，并创建curSum等于所有gas[i]-cost[i]的和
//3. 如果curSum < 0,那么肯定不能取i以及i之前的位置作为起点,所以将i+1记为起点
//4. 遍历所有元素即可得到最后可取i+1的位置
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curSum = 0;
        int totalSum = 0;
        int begindex = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            curSum += gas[i]-cost[i];
            totalSum += gas[i]-cost[i];
            if(curSum < 0)
            {
                begindex = i+1;
                curSum = 0;
            }
        }
        if(totalSum < 0)
            return -1;
        else
            return begindex;
        
    }
};
int main()
{
    
    system("Pause");
}
