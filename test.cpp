#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;

class abb
{
public:
    int width;
    int height;
    abb(int a,int b):width(a),height(b)
    {

    }
};
template <typename T> struct Vec2 {
    T x,y;
     Vec2<T>() : x(T()), y(T()) {}
};
    int main()
    {
        Vec2<float> n;
        cout<<n.x<<" "<<n.y;
        system("Pause");
    }