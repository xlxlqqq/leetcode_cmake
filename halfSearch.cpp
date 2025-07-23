// 二分查找

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int halfSearch(vector<int>& nums, int target){
        int left = 0; 
        int right = nums.size() - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] > target) {
                right = mid - 1;
            } else if(nums[mid] < target) {
                left = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};

int main() {
    std::vector<int> nums{1,2,3,4,5};
    int target = 4;
    Solution solution;
    int result = solution.halfSearch(nums, target);
    cout << result << endl;

    return 0;
}