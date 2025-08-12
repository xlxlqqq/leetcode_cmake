// 生成括号
// 回溯法


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generate(int n) {
        result.clear();
        path.clear();
        if (n <= 0) {
            return result;
        }
        backTrack(n);
        return result;
    }

private:
    int open;
    int close;
    vector<string> result;
    string path;

    void backTrack(int max) {
        if (path.size() == max * 2) {
            result.emplace_back(path);
            return;
        }

        if (open < max) {
            ++open;
            path.push_back('(');
            backTrack(max);
            path.pop_back();
            --open;
        }

        if (close < open) {
            ++close;
            path.push_back(')');
            backTrack(max);
            path.pop_back();
            --close;
        }
    }

};

int main() {
    int n = 3;
    Solution solution;
    vector<string> result = solution.generate(n);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }

    return 0;
}