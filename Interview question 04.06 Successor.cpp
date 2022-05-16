#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>

using namespace std;
//面试题 04.06. 后继者 https://leetcode.cn/problems/successor-lcci/
//

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    // TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    //     TreeNode* cur = root;
    //     TreeNode* bf = nullptr;
    //     while(cur != nullptr)
    //     {
    //         if(cur->val > p->val)
    //         {
    //             bf = cur;
    //             cur = cur->left;
    //         }
    //         else if(cur->val < p->val)
    //         {
    //             cur = cur->right;
    //         }
    //         else// cur->val == p->val
    //         {
    //             break;
    //         }
    //     }
    //     return bf;
    // }
        TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
            stack<TreeNode*> st;
            TreeNode* bf = nullptr;
            if(root != nullptr)
                st.push(root);
            while(!st.empty())
            {
                TreeNode* cur = st.top();
                if(cur != NULL)
                {
                    st.pop();
                    if(cur->right)
                        st.push(cur->right);
                    st.push(cur);
                    st.push(NULL);
                    if(cur->left)
                        st.push(cur->left);
                }
                else
                {
                    st.pop();
                    cur = st.top();
                    if(bf != nullptr && bf->val == p->val)
                    {
                        return cur;
                    }
                    bf = cur;
                    st.pop();
                }
            }
            return nullptr;
    }
};
int main()
{
    
    system("Pause");
}
