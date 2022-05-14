#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>

using namespace std;
//691. 贴纸拼词 https://leetcode.cn/problems/stickers-to-spell-word/
//思路 BFS 状态压缩
class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int n = target.size(); 
        vector<int> dp((1<<n), 0); //定义一个能装下所有状态的数组

        queue<int> q; //BFS队列，用于存储每次增加单个贴纸后的state
        q.push(0); //最开始state等于0

        while (!q.empty()) {
            int begin = q.front();
            q.pop();
            for (auto s: stickers) { //依次遍历每个贴纸单词
                int state = begin; //每次都继承上次的state，保证target的每个字母都只被找到一次

                vector<int> cnt(26);
                for (auto c: s) {
                    cnt[c-'a']++; //比较字母
                }
                for (int i = 0; i < n; i++) {
                    if (cnt[target[i]-'a'] && !(state & (1 << i))) { //当有一样的字母，并且target上该字母的下标还没有被标记在state上时
                        state |= 1 << i; //标记在state上
                        cnt[target[i]-'a']--; //避免重复寻找
                    }
                }
                
                if (dp[state] || state == 0) continue; //没找到就跳过计算该贴纸
                q.push(state); //在队列中更新每取完一个贴纸后的状态
                dp[state] = dp[begin] + 1;//需要的总贴纸数加1
                if (state == (1<<n) - 1) return dp[state]; //当当前state全部填满，就返回
            } 
        }

        return -1;
    }
};
int main()
{
    
    system("Pause");
}
