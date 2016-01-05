#include <iostream>
#include <thread>

static const int num_threads = 10;

//This function will be called from a thread

void call_from_thread(int i, int *data) {
    std::cout << "Launched by thread: " + std::to_string(i) + "\n" << std::endl;
    *(data+i) += 1;
    std::cout << "XXX";
}

int main() {
    std::thread t[num_threads];
    int my_data[num_threads];

    for (int i = 0; i < num_threads; ++i) {
        my_data[i] = 1;
    }
    //Launch a group of threads
    for (int i = 0; i < num_threads; ++i) {
        t[i] = std::thread(call_from_thread, &my_data);
    }

    std::cout << "Launched from the main\n";

    //Join the threads with the main thread
    for (int i = 0; i < num_threads; ++i) {
        t[i].join();
    }

    return 0;
}