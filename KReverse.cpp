// 方法更容易理解，从翻转链表来的更好懂

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {};
};

class Solution {
public:
    ListNode* reverse(ListNode* head, int k) {
        if(!head || k <= 1) {
            return head;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* end = dummy;
        ListNode* pre = dummy;
        while(true) {
            // 找本组的头和尾
            for(int i = 0; i < k; i++) {
                end = end->next;
                if(!end) { break; }
            }
            if(!end) {
                break;
            }

            ListNode* begin = pre->next;  // 本组的第一个
            ListNode* next = end->next;  // 下一组的第一个，暂存
            end->next = nullptr;  // 断开这组和下一组之间的联系

            pre->next = reverse(begin);  // 通用reverse
            begin->next = next;  // 恢复链接
            pre = begin;
            end = begin;
        }
        return dummy->next;

    }

private:
    ListNode* reverse(ListNode* head) {
        if(!head) return nullptr;

        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur) {
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};

int main() {
    vector<int> list_vec{1,2,3,4,5};
    int k = 2;
    ListNode* dummy = new ListNode(0);
    ListNode* cur_node = dummy;
    for(int i = 0; i < list_vec.size(); i++) {
        ListNode* temp = new ListNode(list_vec[i]);
        cur_node->next = temp;
        cur_node = temp;
    }

    Solution solution;
    auto result = solution.reverse(dummy->next, k);

    cur_node = result;
    while(cur_node) {
        cout << cur_node->val << " ";
        cur_node = cur_node->next;
    }
    cout << endl;
    return 0;

}