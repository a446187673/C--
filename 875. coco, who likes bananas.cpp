#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//875. 爱吃香蕉的珂珂 https://leetcode.cn/problems/koko-eating-bananas/
//二分法
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        if(piles.size() == h)
            return piles[piles.size()-1];
        int left = 1;
        int right = piles[piles.size()-1];
        while(left < right)
        {
            int mid = left + (right - left)/2;
            if(eat_out_time(piles,mid) > h)
                left = mid+1;
            else
                right = mid;
        }
        return left;
    }
    int eat_out_time(vector<int> piles, int speed)
    {
        int time = 0;
        for(int i : piles)
        {
            time += i/speed;
            if(i % speed != 0)
                time++;
        }
        return time;
    }
    
};
int main()
{
    
    system("Pause");
}
