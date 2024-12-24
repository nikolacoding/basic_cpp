#include <iostream>
#include <string>
#include <deque>
#include <thread>
using std::string;
using std::deque;
using std::thread;
using namespace std::literals::chrono_literals;

void countdown(int start){
    std::this_thread::sleep_for(std::chrono::seconds(start));
    std::printf("Izvrseno odbrojavanje od %d.\n", start);
}

int main(void){
    deque<int> dq = {1, 2, 3, 4, 5};
    thread** threads = new thread*[5];

    for (int i = 0; i < dq.size(); i++){
        threads[i] = new thread(countdown, dq[i]);
        threads[i]->join();
    }
    
    for (int i = 0; i < dq.size(); i++)
        delete threads[i];
    delete[] threads;
}