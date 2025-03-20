#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <algorithm>
#include <string>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <bitset>
#include <cmath>
#include <random>
#include <ctime> 

using namespace std;

class Solution {
    private:
        double radius;
        double x_center;
        double y_center;
    
    public:
        Solution(double radius, double x_center, double y_center) : radius(radius), x_center(x_center), y_center(y_center) {
            // 使用 time() 作為隨機數種子
            std::srand(std::time(0));
        }
    
        std::vector<double> randPoint() {
            // 產生 [0, 1) 之間的隨機數
            double u1 = static_cast<double>(std::rand()) / RAND_MAX;
            double u2 = static_cast<double>(std::rand()) / RAND_MAX;
    
            // 計算半徑和角度
            double r = std::sqrt(u1) * radius;
            double theta = u2 * 2 * M_PI;
    
            // 計算 x 和 y 座標
            double x = x_center + r * std::cos(theta);
            double y = y_center + r * std::sin(theta);
    
            return {x, y};
        }
    };

int main()
{
    Solution a = Solution(1,0,0);
    vector<double> test(2,0);
    for(int i = 0; i < 100;i++){
        test = a.randPoint();
        cout<<"("<<test[0]<<","<<test[1]<<")"<<endl;
    }
    return 0;
}
