// 最小缺失正整数
// 巧妙使用hash表，把自己本身作为哈希表
// 把当前位置上的数字，放在该放的位置上：如果当前位置是3，那就把3的位置上放一个3（或者-1）

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int minMiss(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] <= 0 || nums[i] > n) {
                nums[i] = -1;
            }
        }

        int position = 0;
        while(position < n){
            if(-1 != nums[position]) {
                if(nums[position] - 1 > position) {
                    int temp = nums[nums[position] - 1];
                    if(temp == -1) {
                        position++;
                        continue;
                    }
                    nums[nums[position] - 1] = -1;
                    nums[position] = temp;
                    continue;
                } else {
                    nums[nums[position] - 1] = -1;
                }
            }
            ++position;
        }

        for(int i = 0; i < n; i++) {
            if(-1 != nums[i]) {
                return 1 + i;
            }
        }
        return 1 + n;
            
        
    }

private:
    void mySwap(int& a, int& b){
        int temp = a ^ b;
        a = temp ^ b;
        b = temp ^ a;
    }
};


int main() {
    vector<int> nums{4,3,1,123,9};
    Solution solution;
    auto result = solution.minMiss(nums);
    cout << result << endl;
    return 0;
}

