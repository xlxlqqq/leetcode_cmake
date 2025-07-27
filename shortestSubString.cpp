//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string substring(string& s, string& t) {
        // 创建一个hash table
        std::unordered_map<char, int> need;
        for(int i = 0; i < t.size(); i++){
            need[t[i]] += 1;
        }

        int left = 0, right = 0;
        int length = s.size() + 1;
        int begin = 0;
        int count = t.size();
        while(left <= right && right < s.size()){
            if(need.find(s[right]) != need.end()){
                count -= 1;
            }
            need[s[right]] -= 1;  // 不论在不在都-1，这样不是t里面的字符会成为负数，后面可以用
            if(0 == count) {
                while(left <= right && need[s[left]] < 0){
                    need[s[left]] += 1;
                    left += 1;
                }
                if(right - left + 1 < length) {
                    length = right - left + 1;
                    begin = left;
                }
                need[s[left]] += 1;
                left += 1;
                count += 1;
            }
            right += 1;
        }

        return length == s.size() + 1 ? "" : s.substr(begin, length);
    }
};

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";

    cout << "begin substring" << endl;
    Solution solution;
    auto result = solution.substring(s, t);
    cout << result << endl;
    return 0;
}