class ZeroEvenOdd {
  public ZeroEvenOdd(int n) {
    this.n = n;
  }

  // printNumber.accept(x) outputs "x", where x is an integer.
  public void zero(IntConsumer printNumber) throws InterruptedException {
    for (int i = 0; i < n; ++i) {
      zeroSemaphore.acquire();
      printNumber.accept(0);
      (i % 2 == 0 ? oddSemaphore : evenSemaphore).release();
    }
  }

  public void even(IntConsumer printNumber) throws InterruptedException {
    for (int i = 2; i <= n; i += 2) {
      evenSemaphore.acquire();
      printNumber.accept(i);
      zeroSemaphore.release();
    }
  }

  public void odd(IntConsumer printNumber) throws InterruptedException {
    for (int i = 1; i <= n; i += 2) {
      oddSemaphore.acquire();
      printNumber.accept(i);
      zeroSemaphore.release();
    }
  }

  private int n;
  private Semaphore zeroSemaphore = new Semaphore(1);
  private Semaphore evenSemaphore = new Semaphore(0);
  private Semaphore oddSemaphore = new Semaphore(0);
}
