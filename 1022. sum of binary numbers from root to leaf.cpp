#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//1022. 从根到叶的二进制数之和 https://leetcode.cn/problems/sum-of-root-to-leaf-binary-numbers/

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
    vector<vector<int>> res;
    vector<int> temp;
    void backtracking(TreeNode* cur)
    {
        temp.push_back(cur->val);
        if(cur->left == nullptr && cur->right == nullptr)
        {
            res.push_back(temp);
            return;
        }
        
        if(cur->left)
        {
            backtracking(cur->left); //有一个递归，就有一个回溯
            temp.pop_back();
        }
        if(cur->right)
        {
            backtracking(cur->right);
            temp.pop_back();
        }
    }
    int sumRootToLeaf(TreeNode* root) {
        if(root != nullptr)
            backtracking(root);
        
        
        int sum = 0;
        for(auto nums : res)
        {
            int curnum = 0;
            int beishu = 1;
            for(int i = nums.size() - 1; i>=0 ; i--)
            {
                curnum += beishu*nums[i];
                beishu = beishu*2;
            }
            // cout<<curnum<<" ";
            sum += curnum;
        }
        // cout<<sum;
        return sum;
    }
};
int main()
{
    TreeNode* root = new TreeNode(1);
    TreeNode* l1 = new TreeNode(0);
    TreeNode* r1 = new TreeNode(1);
    TreeNode* l11 = new TreeNode(0);
    TreeNode* l12 = new TreeNode(1);
    TreeNode* r11 = new TreeNode(0);
    TreeNode* r12 = new TreeNode(1);
    
    root->left = l1;
    root->right = r1;
    l1->left = l11;
    l1->right = l12;
    r1->left = r11;
    r1->right = r12;

    Solution s1;
    s1.sumRootToLeaf(root);
    system("Pause");
}
