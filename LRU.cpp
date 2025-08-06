// 用双向链表存KV能O(1)往前挪
// map里面存的是迭代器，之前其实想到了，但是只想到存位置索引，没想道直接存迭代器
// LRU

#include <unordered_map>
#include <iostream>
#include <utility>
#include <queue>
#include <list>

using namespace std;

class LRU {
public:
    LRU(int capacity) : capacity_(capacity) {

    }

    int get(int key) {
        auto position = map_.find(key);
        if(position != map_.end()) {
            // 把position->second整体裁剪到kv_.begin()的位置
            kv_.splice(kv_.begin(), kv_, position->second);
            return position->second->second;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        auto position = map_.find(key);
        if(position != map_.end()) {
            position->second->second = value;
            kv_.splice(kv_.begin(), kv_, position->second);
        } else {
            if(kv_.size() == capacity_) {
                
                int need_rm = kv_.back().first;
                kv_.pop_back();
                map_.erase(need_rm);
            } 
            auto it = pair<int, int>(key, value);
            kv_.emplace_front(it);
            map_[key] = kv_.begin();
       }
    }


private:
    int capacity_;
    std::list<pair<int, int>> kv_;
    // key + 链表迭代器，从key直接就能找到在双向链表里面的位置
    std::unordered_map<int, list<pair<int, int>>::iterator> map_;

};

int main() {
    auto my_lru = new LRU(2);
    my_lru->put(1, 1);
    my_lru->put(2, 2);
    int result;
    result = my_lru->get(1);
    cout << result << endl;
    my_lru->put(3, 3);
    result = my_lru->get(2);
    cout << result << endl;
    my_lru->put(4, 4);
    result = my_lru->get(1);
    cout << result << endl;
    result = my_lru->get(3);
    cout << result << endl;
    result = my_lru->get(4);
    cout << result << endl;

    return 0;
}