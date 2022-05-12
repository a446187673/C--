#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<algorithm>

using namespace std;
//968. 监控二叉树 https://leetcode.cn/problems/binary-tree-cameras/
//思路

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    int res = 0;
    int travelnode(TreeNode* cur)
    {
        if(cur == nullptr)
            return 2;
        int left = travelnode(cur->left);
        int right = travelnode(cur->right);

        if(left == 2 && right == 2)
            return 0;
        else if(left == 0 || right == 0)
        {
            return 1;
            res++;
        }
        else if(left == 1 || right == 1)
            return 2;

    }
    int minCameraCover(TreeNode* root) {
        if(root!=nullptr)
            travelnode(root);
        return res;
    }
};
int main()
{
    TreeNode* root = new TreeNode(0);
    TreeNode* left1 = new TreeNode(0);
    TreeNode* left2 = new TreeNode(0);
    TreeNode* right1 = new TreeNode(0);
    root->left = left1;
    left1->left = left2;
    left1->right = right1;
    Solution s1;
    cout<<s1.minCameraCover(root);
    
    
    system("Pause");
}
