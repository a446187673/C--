#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//719. 找出第 K 小的数对距离 https://leetcode.cn/problems/find-k-th-smallest-pair-distance/
//值域二分
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), left = 0, right = nums.back() - nums.front();
        while (left < right) {
            int mid =left + (right - left) / 2;
            int cnt = 0;
            //计算差值小于等于mid的数对的数量
            for (int i = 0, j = 0; j < n; j++) {
                while (nums[j] - nums[i] > mid) {
                    i++;
                }
                cnt += j - i;
            }
            if (cnt >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
int main()
{
    Solution s1;
    vector<int> vec{1,1,3};
    cout<<s1.smallestDistancePair(vec,1);
    system("Pause");
}
