// https://cloud.tencent.com/developer/article/1502128
// 双指针，左右指针作为围栏

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int water(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int max = 0;
        int left_max = height[left], right_max = height[right];

        while(left <= right) {
            left_max = std::max(left_max, height[left]);
            right_max = std::max(right_max, height[right]);
            if(left_max < right_max) {
                max += left_max - height[left];
                left++;
            } else {
                max += right_max - height[right];
                right--;
            }
        }
        return max;
    }
};

int main() {
    vector<int> height{0,1,0,2,1,0,1,3,2,1,2,1};
    Solution solution;
    int result = solution.water(height);
    cout << result << endl;
    return 0;

}