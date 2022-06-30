#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>

using namespace std;
//513. 找树左下角的值 https://leetcode.cn/problems/find-bottom-left-tree-value/
//bfs
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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        int res = root->val;
        while(que.empty() == false)
        {
            int size = que.size();
            TreeNode* cur;
            for (int i = 0; i < size; i++)
            {   
                cur = que.front();
                que.pop();
                if (cur->right)
                    que.push(cur->right);
                if (cur->left)
                    que.push(cur->left);
            }
            res = cur->val;
        }
        return res;
    }
};
int main()
{
    
    system("Pause");
}
