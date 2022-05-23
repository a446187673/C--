#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//965. 单值二叉树 https://leetcode.cn/problems/univalued-binary-tree/

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
    int bf;
    int f = 0;
    void order(TreeNode* cur,int bf)
    {
        if(cur == nullptr)
            return;
        if(cur->val != bf)
            f = -1;
        if(cur->left)
            order(cur->left,bf);
        if(cur->right)
            order(cur->right,bf);
    }
    bool isUnivalTree(TreeNode* root) {
        bf = root->val;
        order(root,bf);
        cout<<f;
        if(f == -1)
            return false;
        else
            return true;
    }
};
int main()
{
    
    system("Pause");
}
