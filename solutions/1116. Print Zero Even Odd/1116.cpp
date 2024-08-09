// LeetCode doesn't support C++20 yet, so we don't have std::counting_semaphore
// or binary_semaphore.
#include <semaphore.h>

class ZeroEvenOdd {
 public:
  ZeroEvenOdd(int n) : n(n) {
    sem_init(&zeroSemaphore, /*pshared=*/0, /*value=*/1);
    sem_init(&evenSemaphore, /*pshared=*/0, /*value=*/0);
    sem_init(&oddSemaphore, /*pshared=*/0, /*value=*/0);
  }

  ~ZeroEvenOdd() {
    sem_destroy(&zeroSemaphore);
    sem_destroy(&evenSemaphore);
    sem_destroy(&oddSemaphore);
  }

  // printNumber(x) outputs "x", where x is an integer.
  void zero(function<void(int)> printNumber) {
    for (int i = 0; i < n; ++i) {
      sem_wait(&zeroSemaphore);
      printNumber(0);
      sem_post(&(i % 2 == 0 ? oddSemaphore : evenSemaphore));
    }
  }

  void even(function<void(int)> printNumber) {
    for (int i = 2; i <= n; i += 2) {
      sem_wait(&evenSemaphore);
      printNumber(i);
      sem_post(&zeroSemaphore);
    }
  }

  void odd(function<void(int)> printNumber) {
    for (int i = 1; i <= n; i += 2) {
      sem_wait(&oddSemaphore);
      printNumber(i);
      sem_post(&zeroSemaphore);
    }
  }

 private:
  const int n;
  sem_t zeroSemaphore;
  sem_t evenSemaphore;
  sem_t oddSemaphore;
};
