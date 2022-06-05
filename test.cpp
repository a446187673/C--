#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;
float *abb = NULL;
void solution(float* abb)
{
    abb[2] = 123;
}
    int main()
    {
        
        abb = new float[1000];
        solution(abb);
        abb[1] = 2026;
        cout<<abb[2];
        system("Pause");
    }