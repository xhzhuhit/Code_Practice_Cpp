#include <thread>
#include <iostream>
#include <unistd.h>
#include <mutex>

std::mutex g_mutex;

void thread_function() {
    g_mutex.lock();
    std::cout << "inside thread::ID: " << std::this_thread::get_id() << std::endl;
    g_mutex.unlock();
}

int main() {
    std::thread threadObj1(thread_function);
    std::thread threadObj2(thread_function);
    //sleep(1);
    usleep(10000);
    std::cout << "thread1 id: " << threadObj1.get_id() << std::endl;
    std::cout << "thread2 id: " << threadObj2.get_id() << std::endl;
    
    threadObj1.join();
    threadObj2.join();

    return 0;
}
