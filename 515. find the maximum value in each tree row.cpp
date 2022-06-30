#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>

using namespace std;
//515. 在每个树行中找最大值 https://leetcode.cn/problems/find-largest-value-in-each-tree-row/
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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> que;
        vector<int> res;
        if(root == nullptr)
            return res;
        que.push(root);
        while (que.empty() == false)
        {
            int size = que.size();
            int cur_max_value = INT_MIN;
            for (int i = 0; i < size; i++)
            {
                TreeNode* cur = que.front();
                que.pop();
                cur_max_value = max(cur_max_value,cur->val);
                if(cur->left)
                    que.push(cur->left);
                if(cur->right)
                    que.push(cur->right);
            }
            res.push_back(cur_max_value);
        }
        return res;
    }
};
int main()
{
    
    system("Pause");
}
