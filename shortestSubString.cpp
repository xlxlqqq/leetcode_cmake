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
                need[s[right]] -= 1;  
            }
            right+=1;
            if(0 == count) {
                while(left < right && 0 == count) {
                    if(need.find(s[left]) != need.end()){
                        count += 1;
                        
                    }
                    need[s[left]] -= 1;
                    left += 1;
                }
                if(right - left < length && count == 0) {
                    cout << "find substring" << length << endl;
                    length = right - left;
                    begin = left;
                }
                // 再走一个left，新旅途
                need[s[left]] += 1;
                left += 1;
                count += 1;
            }
        }
        cout << "length: " << length << endl;
        cout << "begin: " << begin << endl;
        return (length == s.size() + 1) ? "" : s.substr(begin, length);
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