// LeetCode doesn't support C++20 yet, so we don't have std::counting_semaphore
// or binary_semaphore.
#include <semaphore.h>

class FizzBuzz {
 public:
  FizzBuzz(int n) : n(n) {
    sem_init(&fizzSemaphore, /*pshared=*/0, /*value=*/0);
    sem_init(&buzzSemaphore, /*pshared=*/0, /*value=*/0);
    sem_init(&fizzbuzzSemaphore, /*pshared=*/0, /*value=*/0);
    sem_init(&numberSemaphore, /*pshared=*/0, /*value=*/1);
  }

  ~FizzBuzz() {
    sem_destroy(&fizzSemaphore);
    sem_destroy(&buzzSemaphore);
    sem_destroy(&fizzbuzzSemaphore);
    sem_destroy(&numberSemaphore);
  }

  // printFizz() outputs "fizz".
  void fizz(function<void()> printFizz) {
    for (int i = 1; i <= n; ++i)
      if (i % 3 == 0 && i % 15 != 0) {
        sem_wait(&fizzSemaphore);
        printFizz();
        sem_post(&numberSemaphore);
      }
  }

  // printBuzz() outputs "buzz".
  void buzz(function<void()> printBuzz) {
    for (int i = 1; i <= n; ++i)
      if (i % 5 == 0 && i % 15 != 0) {
        sem_wait(&buzzSemaphore);
        printBuzz();
        sem_post(&numberSemaphore);
      }
  }

  // printFizzBuzz() outputs "fizzbuzz".
  void fizzbuzz(function<void()> printFizzBuzz) {
    for (int i = 1; i <= n; ++i)
      if (i % 15 == 0) {
        sem_wait(&fizzbuzzSemaphore);
        printFizzBuzz();
        sem_post(&numberSemaphore);
      }
  }

  // printNumber(x) outputs "x", where x is an integer.
  void number(function<void(int)> printNumber) {
    for (int i = 1; i <= n; ++i) {
      sem_wait(&numberSemaphore);
      if (i % 15 == 0)
        sem_post(&fizzbuzzSemaphore);
      else if (i % 3 == 0)
        sem_post(&fizzSemaphore);
      else if (i % 5 == 0)
        sem_post(&buzzSemaphore);
      else {
        printNumber(i);
        sem_post(&numberSemaphore);
      }
    }
  }

 private:
  const int n;
  sem_t fizzSemaphore;
  sem_t buzzSemaphore;
  sem_t fizzbuzzSemaphore;
  sem_t numberSemaphore;
};
