#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>

using namespace std;
//668. 乘法表中第k小的数 https://leetcode.cn/problems/kth-smallest-number-in-multiplication-table/
//思路 二分查找
// class Solution {
// public:
//     int findKthNumber(int m, int n, int k) {
//         vector<vector<int>> nums(m,(vector<int>(n,0)));
//         map<int,int> resmap;
//         for (int i = 0; i < m; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 nums[i][j] = (i+1)*(j+1);
//                 resmap[nums[i][j]]++;
//             }
//         }
//         int res;
//         auto it = resmap.begin();
//         auto bf = resmap.begin();
//         while(k>0 && it != resmap.end())
//         {
            
//             k = k - (*it).second;
//             bf =it;
//             it++;
//         }
//         // // if(k <= 0)
//         // cout<<k<<endl;
//         return bf->first;
//     }
// }; 哈希表，超时
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int left = 1, right = m * n;
        while (left < right) {
            int x = left + (right - left) / 2;
            int count = x / n * n;
            for (int i = x / n + 1; i <= m; ++i) {
                count += x / i;
            }
            if (count >= k) {
                right = x;
            } else {
                left = x + 1;
            }
        }
        return left;
    }
};

int main()
{
    Solution s1;
    cout<<s1.findKthNumber(9895,28405,100787757);
    system("Pause");
}
