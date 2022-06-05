#include<iostream>
#include<vector>
#include<string>
#include<random>
#include<algorithm>

using namespace std;
//478. 在圆内随机生成点 https://leetcode.cn/problems/generate-random-point-in-a-circle/
//数学模拟 超时
class Solution {
public:
    double x,y,r;
    Solution(double radius, double x_center, double y_center) {
        this->r = radius;
        this->x = x_center;
        this->y = y_center;
    }
    
    vector<double> randPoint() {
        uniform_real_distribution<double> randomX(x-r,x+r);
        std::random_device rd;
        default_random_engine eng(rd());
        double pointX = randomX(eng);
        double maxY = sqrt(pow(r,2)-pow((pointX - x),2))+y;
        double minY = -sqrt(pow(r,2)-pow((pointX - x),2))+y;
        uniform_real_distribution<double> randomY{minY,maxY};
        double pointY =  randomY(eng);
        vector<double> vec{pointX,pointY};
        return vec;
    }
};
//拒绝采样
class Solution {
private:
    mt19937 gen{random_device{}()};
    uniform_real_distribution<double> dis;
    double xc, yc, r;

public:
    Solution(double radius, double x_center, double y_center): dis(-radius, radius), xc(x_center), yc(y_center), r(radius) {}
    
    vector<double> randPoint() {
        while (true) {
            double x = dis(gen), y = dis(gen);
            if (x * x + y * y <= r * r) {
                return {xc + x, yc + y};
            }
        }
    }
};
int main()
{
    Solution s1(1.0, 0.0,0.0);
    s1.randPoint();
    system("Pause");
}
