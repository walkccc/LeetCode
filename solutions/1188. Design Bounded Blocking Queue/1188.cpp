// LeetCode doesn't support C++20 yet, so we don't have std::counting_semaphore
// or binary_semaphore.
#include <semaphore.h>

class BoundedBlockingQueue {
 public:
  BoundedBlockingQueue(int capacity) {
    sem_init(&enqueueSemaphore, /*pshared=*/0, /*value=*/capacity);
    sem_init(&dequeueSemaphore, /*pshared=*/0, /*value=*/0);
  }

  ~BoundedBlockingQueue() {
    sem_destroy(&enqueueSemaphore);
    sem_destroy(&dequeueSemaphore);
  }

  void enqueue(int element) {
    sem_wait(&enqueueSemaphore);
    q.push(element);
    sem_post(&dequeueSemaphore);
  }

  int dequeue() {
    sem_wait(&dequeueSemaphore);
    const int element = q.front();
    q.pop();
    sem_post(&enqueueSemaphore);
    return element;
  }

  int size() {
    return q.size();
  }

 private:
  queue<int> q;
  sem_t enqueueSemaphore;
  sem_t dequeueSemaphore;
};
