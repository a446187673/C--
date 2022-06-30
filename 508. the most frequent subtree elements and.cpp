#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>

using namespace std;
//508. 出现次数最多的子树元素和 https://leetcode.cn/problems/most-frequent-subtree-sum/

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
    vector<int> sums;
    int dfs(TreeNode* node)
    {
        if(node == nullptr)
            return 0;
        int leftsum = dfs(node->left);
        int rightsum = dfs(node->right);

        sums.push_back(node->val);
        if(node->left)
            sums[sums.size()-1] += leftsum;
        if(node->right)
            sums[sums.size()-1] += rightsum;
        return sums[sums.size()-1];
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if(root == nullptr)
            return sums;
        dfs(root);
        unordered_map<int,int> map;
        for(int i : sums)
        {
            map[i]++;
        }
        int maxvalue = INT_MIN;
        for(auto p : map)
            maxvalue = max(maxvalue,p.second);
        vector<int> res;
        for(auto p : map)
        {
            if(p.second == maxvalue)
                res.push_back(p.first);
        }
        return res;
    }
};
int main()
{
    
    system("Pause");
}
