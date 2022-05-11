#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>

using namespace std;
//449. 序列化和反序列化二叉搜索树 https://leetcode.cn/problems/serialize-and-deserialize-bst
//思路 1.采用前序遍历序列化BFS
//2.反序列化时根据前序遍历顺序返回

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Codec {
public:
    string vectostring(const vector<int> vec)
    {
        string res;
        if(vec.size()==0)
        return res;
        int endsize = vec.size()-1;
        for (int i = 0; i < vec.size()-1; i++)
        {
            res+=to_string(vec[i]);
            res.push_back(',');
        }
        res+=to_string(vec[endsize]);
        return res;
    }
    vector<int> strtovector(string& s) {
        vector<int> res;
        int startindex = 0;
        int curindex = 0;
        while(curindex<s.size())
        {
            while(curindex<s.size() && s[curindex] ==',')
            {
                curindex++;
            }
            startindex = curindex;
            while(curindex<s.size() && s[curindex] !=',')
            {
                curindex++;
            }
            if(startindex<s.size())
            {
                res.emplace_back(stoi(s.substr(startindex, curindex - startindex)));                
            }
        }
        return res;
        
    }
    string serialize(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> res;
        if(root != nullptr)
            stk.push(root);
        while(!stk.empty())
        {
            TreeNode* cur = stk.top();
            if(cur != NULL)
            {
                stk.pop();

                if(cur->right)
                    stk.push(cur->right);
                if(cur->left)
                    stk.push(cur->left);
                stk.push(cur);
                stk.push(NULL);

            }
            else
            {
                stk.pop();
                cur = stk.top();
                res.push_back(cur->val);
                stk.pop();
            }

        }
        string re =vectostring(res);
        return re;   
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()== 0)
            return nullptr;
        vector<int> vec = strtovector(data);
        TreeNode* root = new TreeNode(vec[0]);
        vector<int> leftvec;
        vector<int> rightvec;
        for(int val : vec)
        {
            if(val < vec[0])
                leftvec.push_back(val);
            else if(val > vec[0])
                rightvec.push_back(val);
        }
        root->left = deserialize(vectostring(leftvec));
        root->right = deserialize(vectostring(rightvec));
        return root;     
    }
};
int main()
{
    string s = "2,1,3";
    Codec s1;
    s1.deserialize(s);
    system("Pause");
}
