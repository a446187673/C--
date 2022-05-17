#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>

using namespace std;
//953. 验证外星语词典 https://leetcode.cn/problems/verifying-an-alien-dictionary/

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> mapping;
        for (int i = 0; i < order.size(); ++i) {
            mapping[order[i]] = i;
        }
        vector<string> decrypt;
        for (string& word : words) {
            string decryptWord;
            for (char c : word) {
                decryptWord += 'a' + mapping[c];
            }
            decrypt.push_back(decryptWord);
        }
        return is_sorted(decrypt.begin(), decrypt.end());
    }
};
int main()
{
    
    system("Pause");
}
