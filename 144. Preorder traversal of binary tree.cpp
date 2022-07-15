#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>

using namespace std;
//144. 二叉树的前序遍历 https://leetcode.cn/problems/binary-tree-preorder-traversal/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//递归法
class Solution {
public:
    //可以设置返回值来记录节点的值
    vector<int> res;
    void preoder(TreeNode* root)
    {
        if(root == nullptr)
            return;
        {
            //中。处理节点
            res.push_back(root->val);
        }
        preoder(root->left);//左
        preoder(root->right);//右
    }
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return res;
    }
};
//迭代法
class Solution2 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        if(root == nullptr)
            return res;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* cur = st.top();
            if(cur != NULL)
            {
                st.pop();
                //右
                if(cur->right)
                    st.push(cur->right);
                //左
                if(cur->left)
                    st.push(cur->left);
                //中
                    st.push(cur);
                    st.push(NULL);
            }
            else
            {
                st.pop();
                cur = st.top();
                {
                    //处理节点
                    res.push_back(cur->val);
                }
                st.pop();
            } 
        }
        return res;
    }
};
int main()
{
    
    system("Pause");
}
