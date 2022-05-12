#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//714. 买卖股票的最佳时机含手续费 https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
//思路 
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        
        int res = 0;
        int minprice = prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            if(prices[i] < minprice) //当股票价格最低时买入
            {
                minprice = prices[i];
            }

            if(prices[i] > minprice && prices[i]-fee <= minprice)  //不赚钱，不卖出
            {
                continue;
            }
            if(prices[i] > minprice && prices[i]-fee > minprice) 
            {

                res += prices[i] - minprice - fee; //卖出并赚取利润
                minprice = prices[i] - fee;  //如果留到下次卖出，那么此时手上能赚取利润的剩余值
            }
        }
        return res;
        
    }
};
int main()
{
    
    system("Pause");
}
