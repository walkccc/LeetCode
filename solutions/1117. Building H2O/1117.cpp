// LeetCode doesn't support C++20 yet, so we don't have std::counting_semaphore
// or binary_semaphore.
#include <semaphore.h>

class H2O {
 public:
  H2O() {
    sem_init(&hSemaphore, /*pshared=*/0, /*value=*/1);
    sem_init(&oSemaphore, /*pshared=*/0, /*value=*/0);
  }

  ~H2O() {
    sem_destroy(&hSemaphore);
    sem_destroy(&oSemaphore);
  }

  void hydrogen(function<void()> releaseHydrogen) {
    sem_wait(&hSemaphore);
    ++h;
    // releaseHydrogen() outputs "H". Do not change or remove this line.
    releaseHydrogen();
    if (h % 2 == 0)
      sem_post(&oSemaphore);
    else
      sem_post(&hSemaphore);
  }

  void oxygen(function<void()> releaseOxygen) {
    sem_wait(&oSemaphore);
    // releaseOxygen() outputs "O". Do not change or remove this line.
    releaseOxygen();
    sem_post(&hSemaphore);
  }

 private:
  sem_t hSemaphore;
  sem_t oSemaphore;
  int h = 0;
};
