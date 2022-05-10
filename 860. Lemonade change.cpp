#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;
//860. 柠檬水找零 https://leetcode.cn/problems/lemonade-change/
//思路 1.建立一个unordered_map 用于储存手上的零钱
//2.每次需要找零的时候检查，如果没有就返回false，检查到最后都行就返回true
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> changes;
        changes.emplace(5,0);
        changes.emplace(10,0);
        for(int i : bills)
        {
            if(i==5)
            {
                changes[5]++;
            }
            else if(i==10)
            {
                changes[10]++;
                changes[5]--;
            }
            else if(i==20)
            {
                changes[5]--;
                if(changes[10]>0)
                    changes[10]--; //两种情况，1.有10元优先找10元。2.没有10元再找两个5元
                else
                 changes[5]=changes[5]-2;

            }
            if(changes[10]<0 || changes[5]<0)
                return false;
        }
        return true;;
    }
};

int main()
{
    unordered_map<int, int> hashmap;
    hashmap.emplace(1, 0);
    hashmap.emplace(2, 0);
    auto it = hashmap.begin();
    for (; it != hashmap.end(); it++)
    {
        cout << it->first << "  " << it->second << endl;
    }
    system("Pause");
}