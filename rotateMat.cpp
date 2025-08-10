// 螺旋矩阵
// 抽象出一个小函数来，实现[x0,y0]到[x1,y1]的遍历
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> rotateMat(vector<vector<int>>& nums) {
        int x = nums[0].size();
        int y = nums.size();
        int circle = (std::min(x, y) + 1) / 2;
        for(int i = 0; i < circle; i++) {  // loop 圈数
            int begin_x = i;
            int end_x = x - i - 1;
            int begin_y = i;
            int end_y = y - i - 1;
            travel(nums, begin_x, begin_y, end_x, end_y);
        }
        return result;
    }

private:
    vector<int> result;
    void travel(vector<vector<int>>& nums, int begin_x, int begin_y, int end_x, int end_y) {
        int x = end_x - begin_x + 1;
        int y = end_y - begin_y + 1;
        if(x == 1) {
            for(int i = begin_y; i <= end_y; i++) {
                result.emplace_back(nums[i][begin_x]);
            }
            return;
        } 
        if(y == 1) {
            for(int i = begin_x; i <= end_x; i++) {
                result.emplace_back(nums[begin_y][i]);
            }
            return;
        }

        // 
        for(int j = 0; j < x - 1; j++){
            result.emplace_back(nums[begin_y][begin_x + j]);
        }

        for(int j = 0; j < y - 1; j++){
            result.emplace_back(nums[begin_y + j][end_x]);
        }

        for(int j = 0; j < x - 1; j++){
            result.emplace_back(nums[end_y][end_x - j]);
        }

        for(int j = 0; j < y - 1; j++){
            result.emplace_back(nums[end_y - j][begin_x]);
        }
    }
};

int main() {
    vector<vector<int>> nums;
    nums.emplace_back(vector<int>{1,2,3,4});
    nums.emplace_back(vector<int>{5,6,7,8});
    nums.emplace_back(vector<int>{9,10,11,12});

    Solution solution;
    vector<int> result = solution.rotateMat(nums);
    for(auto num : result) {
        cout << num << endl;
    }

    return 0;
}