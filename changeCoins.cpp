// 最少硬币个数
// 动态规划

#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int change(vector<int>& coins, int money) {
        vector<int> dp(money + 1, INT_MAX - 1);
        dp[0] = 0;
        for(int i = 1; i < money + 1; i++) {
            for(int j = 0; j < coins.size(); j++) {
                if(i - coins[j] < 0) {
                    continue;
                } else {
                    dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
                }
            }
        }
        if(dp.back() == INT_MAX - 1) return -1;
        return dp.back();
    }
};

int main() {
    vector<int> coins{2};
    int money = 3;
    Solution solution;
    int result = solution.change(coins, money);
    cout << result << endl;
    return 0;
}