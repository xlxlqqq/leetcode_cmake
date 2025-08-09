

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> ipAddress(string& s) {
        count = 0;
        result.clear();
        if(s.size() < 4 || s.size() > 12) {
            return result;
        }
        backTrack(s, 0);
        return result;
    }

private:
    vector<string> result;
    int count;

    void backTrack(string& s, int begin) {
        if(count == 3) {
            if(isValid(s, begin, s.size() - 1)) {
                result.push_back(s);
            }
            return;
        }

        for(int i = begin; i < s.size(); i++) {
            if(isValid(s, begin, i)) {
                s.insert(s.begin() + i + 1, '.');
                ++count;
                backTrack(s, i + 2);
                --count;
                s.erase(s.begin() + i + 1);
            } else {
                break;
            }
        }
    }

    bool isValid(string& s, int begin, int end) {
        int length = end - begin + 1;
        if(length < 0 || length > 3) {
            return false;
        }
        if(end < begin) {
            return false;
        }

        if(s[begin] == '0' && length > 1) { return false; }
        int sum = 0;
        for(int i = begin; i <= end; i++) {
            if(s[i] > '9' || s[i] < '0') return false;
            sum = (s[i] - '0') + sum * 10;
        }
        if(sum > 255) {
                return false;
        }
        return true;
    }

};

int main() {
    string s = "25525511131";
    Solution solution;
    vector<string> result = solution.ipAddress(s);

    for (const auto& ip : result) cout << ip << '\n';
    return 0;

}