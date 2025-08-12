#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    void reverse(string& s) {
        if (s.empty()) {
            return;
        }

        // reverse
        reverse(s, 0, s.size() - 1);

        int begin = 0;
        for (int i = 0; i <= s.size(); i++) {
            if (i == s.size() || s[i] == ' ') {
                reverse(s, begin, i - 1);
                begin = i + 1;
            }
        }
    }

private:

    void reverse(string& s, int begin, int end) {
        if (begin > end) {
            return;
        }

        int left = begin;
        int right = end;

        while (left < right) {
            mySwap(s[left], s[right]);
            ++left;
            --right;
        }
    }

    void mySwap(char& a, char& b) {
        char temp = a;
        a = b;
        b = temp;
    }

};

int main() {
    string myString = "hello world";

    Solution solution;
    solution.reverse(myString);
    cout << myString << endl;

    return 0;
}
