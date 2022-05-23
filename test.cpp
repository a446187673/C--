#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string> q;
        const int N = start.size();
        q.push(start);
        int step = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int s = 0; s < size; s++) {
                auto cur = q.front(); q.pop();
                if (cur == end) {
                    return step;
                }
                for (int i = 0; i < N; i++) {
                    for (char n : {'A', 'C', 'G', 'T'}) {
                        string next = cur.substr(0, i) + n + cur.substr(i + 1);
                        if (next == cur) continue;
                        for (auto it = bank.begin(); it < bank.end(); ++it) {
                            if (*it == next) {
                                q.push(next);
                                bank.erase(it);
                                break;
                            }
                        }
                    }
                }
            }
            step += 1;
        }
        return -1;
    }
};
    int main()
    {
        string s1 = "101";
        cout<<stoi(s1);
    // unordered_map<int, int> hashmap;
    // hashmap.emplace(1, 0); //当哈希表中没有该key的时候才会添加
    // hashmap.emplace(2, 0); //可以在括号内直接输入需要的两个元素的值
    // auto it = hashmap.begin();
    // for (; it != hashmap.end(); it++)
    // {
    //     cout << it->first << " " << it->second << ",";
    // }
    system("pause");
    }