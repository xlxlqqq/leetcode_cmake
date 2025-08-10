// 回文链表
// 存数组可以，也可以翻转后半段和前半段进行比较，双指针找中点
// 联想到K个一组翻转链表
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {};
};

class Solution {
public:
    bool judge(ListNode* head) {
        if(!head) return true;
        vector<int> list_vec;
        ListNode* cur_node = head;
        while(cur_node) {
            list_vec.emplace_back(cur_node->val);
            cur_node = cur_node->next;
        }

        int left = 0, right = list_vec.size() - 1;
        while(left < right) {
            if(list_vec[left] != list_vec[right]) {
                return false;
            } else {
                ++left;
                --right;
            }
        }
        return true;
    }
};

int main() {
    vector<int> list_vec{1,2,3,2};
    ListNode* dummy = new ListNode(0);
    ListNode* cur_node = dummy;
    for(auto val : list_vec) {
        ListNode* temp = new ListNode(val);
        cur_node->next = temp;
        cur_node = cur_node->next;
    }

    Solution solution;
    bool result = solution.judge(dummy->next);
    int result_int = (result) ? 1 : 0;
    cout << result_int << endl;

    return 0;
}