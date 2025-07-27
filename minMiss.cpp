#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int minMiss(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] <= 0 || nums[i] > nums.size()) {
                nums[i] = n + 1;
            }
        }
        for(int i = 0; i < nums.size(); i++) {
            int temp = nums[i];
            if(temp >= n) {
                continue;
            } else {
                nums[temp - 1] = -1;
            }
        }

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                return i + 1;
            }
        }
        return n + 1;
    }
};


int main() {
    vector<int> nums{4,3,7,123,9};
    Solution solution;
    auto result = solution.minMiss(nums);
    cout << result << endl;
    return 0;
}

