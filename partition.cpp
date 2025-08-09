// 切割回文子串，回溯
// 切割
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string& str) {
        result.clear();
        path.clear();
        backTrack(str, 0);
        return result;
    }

private:
    vector<vector<string>> result;
    vector<string> path;

    void backTrack(string& str, int begin) {
        if(begin > str.size() - 1) {
            result.push_back(path);
            return;
        }

        for(int i = begin; i < str.size(); i++) {
            if(isValid(str, begin, i)) {
                string substring = str.substr(begin, i - begin + 1);
                path.push_back(substring);
            } else {
                continue;
            }

            backTrack(str, i + 1);
            path.pop_back();
        }
    }

    bool isValid(string& myString, int& begin, int& end) {
        if(myString.size() <= 1) return true;
        int left = begin, right = end;
        while(left < right) {
            if(myString[left] != myString[right]) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
};

int main() {
    string my_string = "aas";

    Solution solution;
    auto result = solution.partition(my_string);
    for(int i = 0; i < result.size(); i++) {
        for(int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}