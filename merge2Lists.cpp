// 合并两个排序链表
// 不能推广到K个排序链表，需要另外找办法

#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {};
};

class Solution {
public:
    ListNode* merge(ListNode* head1, ListNode* head2) {
        if(!head1 && !head2) {
            return nullptr;
        }

        ListNode* dummy1 = new ListNode(0);
        ListNode* dummy2 = new ListNode(0);
        dummy1->next = head1;
        dummy2->next = head2;
        ListNode* cur_node_1 = head1;
        ListNode* cur_node_2 = head2;
        ListNode* cur_node = dummy1;


        while(cur_node_2 && cur_node_1) {
            if(cur_node_1->val > cur_node_2->val) {
                cur_node->next = cur_node_2;
                cur_node_2 = cur_node_2->next;
            } else {
                cur_node->next = cur_node_1;
                cur_node_1 = cur_node_1->next;
            }
            cur_node = cur_node->next;
        }
        if(cur_node_1) {
            cur_node->next = cur_node_1;
        } else {
            cur_node->next = cur_node_2;
        }
        return dummy1->next;
    }
};

int main() {
    vector<int> head1{1,2,5};
    vector<int> head2{3,4,8};
    ListNode* dummy1 = new ListNode(0);
    ListNode* dummy2 = new ListNode(0);
    ListNode* cur_node = dummy1;
    for(int i = 0; i < head1.size(); i++) {
        ListNode* temp = new ListNode(head1[i]);
        cur_node->next = temp;
        cur_node = cur_node->next;
    }
    cur_node = dummy2;
    for(int i = 0; i < head2.size(); i++) {
        ListNode* temp = new ListNode(head2[i]);
        cur_node->next = temp;
        cur_node = cur_node->next;
    }

    Solution solution;
    auto result = solution.merge(dummy1->next, dummy2->next);
    cur_node = result;
    while(cur_node) {
        cout << cur_node->val << endl;
        cur_node = cur_node->next;
    }
    return 0;
}