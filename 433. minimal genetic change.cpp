#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//433. 最小基因变化  https://leetcode-cn.com/problems/minimum-genetic-mutation/
//题解 https://leetcode-cn.com/problems/minimum-genetic-mutation/solution/by-fuxuemingzhu-t1mv/
//BFS 广度优先搜索
//每一轮改变字母，变换成与bank中匹配的序列，就相当于生成了一层子节点
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string> que;
        que.push(start);
        const int n = start.size();
        int step = 0;
        while(!que.empty())
        {
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                string cur = que.front();
                que.pop();
                if(cur == end)
                    return step;  //如果遍历到对应的基因，就返回
                for (int i = 0; i < n; i++)
                {
                    for(char changechar : {'A','C','G','T'})
                    {
                        string nxt = cur.substr(0,i) + changechar + cur.substr(i+1); //依次变动单个基因
                        for(vector<string>::iterator it = bank.begin();it < bank.end(); it++)
                        {
                            if(*it == nxt)
                            {
                                que.push(nxt);
                                bank.erase(it); //注意erase的参数为迭代器
                            }
                        }
                    }
                }
            }
            step++;  //全部找完，step加1，层数加1
        }
        return -1;

    }
};


int main()
{
    Solution s1;
    string start = "AACCGGTT";
    string end = "AACCGGTA";
    vector<string> bank{"AACCGGTA"};
    cout<<s1.minMutation(start,end,bank);

    system("Pause");
}
