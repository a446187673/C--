#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//450. 删除二叉搜索树中的节点 https://leetcode.cn/problems/delete-node-in-a-bst/
//https://leetcode.cn/problems/delete-node-in-a-bst/solution/miao-dong-jiu-wan-shi-liao-by-terry2020-tc0o/
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr)
            return root;
        if(root->val < key)
            root->right = deleteNode(root->right,key);
        else if (root->val > key)
            root->left = deleteNode(root->left,key);
        else
        {
            if(root->left == nullptr)
                return root->right;
            if(root->right == nullptr)
                return root->left;
            TreeNode* rightsleft;
            if(root->right->left)
                rightsleft = root->right->left;
            rightsleft->left = root->left;
            root = root->right;
        }
        return root;
    }
};
int main()
{
    TreeNode* root = new TreeNode(5);
    TreeNode* l1 = new TreeNode(3);
    TreeNode* r1 = new TreeNode(6);
    TreeNode* l11 = new TreeNode(2);
    TreeNode* l12 = new TreeNode(4);
    // TreeNode* r11 = new TreeNode(0);
    TreeNode* r12 = new TreeNode(7);
    
    root->left = l1;
    root->right = r1;
    l1->left = l11;
    l1->right = l12;
    // r1->left = r11;
    r1->right = r12;

    Solution s1;
    s1.deleteNode(root,3);
    system("Pause");
}
