#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//337. 打家劫舍 III https://leetcode.cn/problems/house-robber-iii/
//贪心算法，动态规划
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> robtree(TreeNode* cur)
    {
        if(cur == nullptr)
            return vector<int>{0,0};
        
        vector<int> left = robtree(cur->left);
        vector<int> right = robtree(cur->right);

        int robval = cur->val + left[0]+right[0]; //如果当前节点偷，就代表两个子节点没偷，取这些值的和作为结果

        int notrobval = max(left[0] , left[1]) + max(right[0],right[1]);  //如果当前节点没偷，就代表两个子节点偷了，那么取目前子节点的最优情况

        return vector<int>{notrobval,robval};
    }
    int rob(TreeNode* root) {
        vector<int> res = robtree(root);
        return max(res[0],res[1]);
    }
};
int main()
{
    
    system("Pause");
}
