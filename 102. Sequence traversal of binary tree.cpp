#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>

using namespace std;
//102. 二叉树的层序遍历 https://leetcode.cn/problems/binary-tree-level-order-traversal/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> que;
        if(root == nullptr)
            return res;
        que.push(root);
        while(!que.empty())
        {
            int size = que.size();
            vector<int> curlevel;
            for (int i = 0; i < size; i++)
            {
                TreeNode* cur = que.front();
                que.pop();
                //记录当前点
                curlevel.push_back(cur->val);
                //推入当前点的子节点
                if(cur->left)
                    que.push(cur->left);
                if(cur->right)
                    que.push(cur->right);
            }
            res.push_back(curlevel);
        }
        return res;
    }
};
int main()
{
    
    system("Pause");
}
