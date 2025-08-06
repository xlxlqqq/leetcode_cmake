// 链表两数相加
// 小端
// 模拟过程做进位就行，处理两个链表长度不一样

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
    ListNode* add(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2) {
            return nullptr;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = l1;
        ListNode* pre = dummy;

        int temp = 0;
        while(l1 || l2 || temp != 0) {
            int all;
            if(!l1) {  // l2挪过来
                l1 = new ListNode(0);
                pre->next = l1;
            } 
            if(!l2) {
                l2 = new ListNode(0);
            } 
            all = l1->val + l2->val + temp;
            l1->val = all % 10;
            temp = (all > 9) ? 1 : 0;
            l1 = l1->next;
            l2 = l2->next;
            pre = pre->next;
        }

        return dummy->next;
    }
};

int main() {
    std::vector<int> l1_list{9,9,9,9,9,9,9};
    std::vector<int> l2_list{9,9,9,9};

    ListNode* dummy1 = new ListNode(0);
    ListNode* dummy2 = new ListNode(0);
    auto l1 = dummy1;
    auto l2 = dummy2;
    for(int i = 0; i < l1_list.size(); i++) {
        l1->next = new ListNode(l1_list[i]);
        l1 = l1->next;
    }
    for(int i = 0; i < l2_list.size(); i++) {
        l2->next = new ListNode(l2_list[i]);
        l2 = l2->next;
    }

    Solution solution;
    auto result = solution.add(dummy1->next, dummy2->next);

    while(result){
        cout << result->val << "  ";
        result = result->next;
    }
    cout << endl;

    return 0;
}