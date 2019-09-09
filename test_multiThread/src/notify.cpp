#include <thread>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <vector>
#include <deque>
#include <queue>
#include <unistd.h>

std::mutex mMutex;
std::condition_variable mCondVar;

int num = 0;
std::deque<int> nums;

void thread_get_data() {
    //std::unique_lock<std::mutex> lock(mMutex);
    for (int i = 0; i < 10; ++i) {
        mMutex.lock();
        nums.push_back(num);
        ++num;
        std::cout << "plus num: " << num << std::endl;
        mMutex.unlock();
        mCondVar.notify_one();
        //sleep(1);
    }
}

void thread_use_data() {
    //for (int i = 0; i < 10; ++i) {
    while(1) {
        std::unique_lock<std::mutex> lk(mMutex);
        mCondVar.wait(lk, []{return !nums.empty();});
        int value = nums.front();
        nums.pop_front();
        std::cout << "value: " << value << std::endl;
        lk.unlock();
        //mCondVar.notify_one();
    }
}

int main(int argc, char** argv) {
    std::thread threadObj1(thread_get_data);
    std::thread threadObj2(thread_use_data);
    threadObj1.join();
    threadObj2.join();

    return 0;
}
