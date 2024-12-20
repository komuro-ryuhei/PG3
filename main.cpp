#include <condition_variable>
#include <mutex>
#include <stdio.h>
#include <thread>

std::mutex mtx;
std::condition_variable cv;
int current_thread = 1;

void printThread(int thread_id) {
	std::unique_lock<std::mutex> lock(mtx);
	cv.wait(lock, [thread_id]() { return current_thread == thread_id; });
	printf("thread %d\n", thread_id);
	current_thread++;
	cv.notify_all();
}

int main() {
	std::thread t1(printThread, 1);
	std::thread t2(printThread, 2);
	std::thread t3(printThread, 3);

	t1.join();
	t2.join();
	t3.join();

	return 0;
}