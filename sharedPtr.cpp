

#include <iostream>
#include <mutex>

template <typename T>
class SmartPoint {
private:
    T* point_;
    int* count_;
    std::mutex mtx_;

    void release() {

    }

public:
    SmartPoint() {};

    ~SmartPoint() {
        release();
    }

    // 拷贝构造
    SmartPoint(T& other) : point_(other->point_), count_(other->count_), mtx_(other->mtx_) {
        if(count_) {
            std::unique_lock<std::mutex> lock(mtx_);
            *count_++;
            lock.unlock();
        }
    }

    // 赋值构造
    SmartPoint(T&& other) : point_(other->point_), count_(other->count_), mtx_(other->mtx_)
    {
        other->point_ = nullptr;
        other->count_ = nullptr;
        other->mtx_ = nullptr;
    }

    // 拷贝赋值运算符
    SmartPoint& operator=(const SmartPoint& other) {
        if(this != other) {
            
        }
    }

    // 移动赋值运算符
    SmartPoint& operator=(const SmartPoint&& other) {

    }
    
};