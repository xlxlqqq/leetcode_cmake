// 拿优先队列实现排序
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {};
};

struct cmp {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* merge(std::vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        std::priority_queue<ListNode*, vector<ListNode*>, cmp> my_queue;
        ListNode* cur_node;
        for(int i = 0; i < lists.size(); i++) {
            cur_node = lists[i];
            while(cur_node) {
                my_queue.push(cur_node);
                cur_node = cur_node->next;
            }
        }
        ListNode* dummy = new ListNode(1);
        cur_node = dummy;
        while(!my_queue.empty()) {
            ListNode* temp = my_queue.top();
            my_queue.pop();
            cur_node->next = temp;
            cur_node = cur_node->next;
        }
        return dummy->next;
    }
};


int main() {
    vector<vector<int>> lists;
    lists.emplace_back(vector<int> {1,4,7});
    lists.emplace_back(vector<int> {2,5,8});
    lists.emplace_back(vector<int> {3,6,9});

    std::vector<ListNode*> dummys;
    ListNode* cur_node;
    for(int i = 0; i < lists.size(); i++) {
        ListNode* temp_head = new ListNode(0);
        dummys.emplace_back(temp_head);
        cur_node = temp_head;
        for(int j = 0; j < lists[i].size(); j++) {
            ListNode* temp = new ListNode(lists[i][j]);
            cur_node->next = temp;
            cur_node = cur_node->next;
        }
    }
    std::vector<ListNode*> heads;
    for(auto dummy :dummys) {
        heads.emplace_back(dummy->next);
    }

    Solution solution;
    auto result = solution.merge(heads);
    cur_node = result;
    while(cur_node) {
        cout << cur_node->val << "  ";
        cur_node = cur_node->next;
    }
    cout << endl;
    return 0;
}