// LeetCode doesn't support C++20 yet, so we don't have std::counting_semaphore
// or binary_semaphore.
#include <semaphore.h>

class FooBar {
 public:
  FooBar(int n) : n(n) {
    sem_init(&fooSemaphore, /*pshared=*/0, /*value=*/1);
    sem_init(&barSemaphore, /*pshared=*/0, /*value=*/0);
  }

  ~FooBar() {
    sem_destroy(&fooSemaphore);
    sem_destroy(&barSemaphore);
  }

  void foo(function<void()> printFoo) {
    for (int i = 0; i < n; ++i) {
      sem_wait(&fooSemaphore);
      printFoo();
      sem_post(&barSemaphore);
    }
  }

  void bar(function<void()> printBar) {
    for (int i = 0; i < n; ++i) {
      sem_wait(&barSemaphore);
      printBar();
      sem_post(&fooSemaphore);
    }
  }

 private:
  const int n;
  sem_t fooSemaphore;
  sem_t barSemaphore;
};
