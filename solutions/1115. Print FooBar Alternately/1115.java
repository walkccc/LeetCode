class FooBar {
  public FooBar(int n) {
    this.n = n;
  }

  public void foo(Runnable printFoo) throws InterruptedException {
    for (int i = 0; i < n; ++i) {
      fooSemaphore.acquire();
      printFoo.run();
      barSemaphore.release();
    }
  }

  public void bar(Runnable printBar) throws InterruptedException {
    for (int i = 0; i < n; ++i) {
      barSemaphore.acquire();
      printBar.run();
      fooSemaphore.release();
    }
  }

  private int n;
  private Semaphore fooSemaphore = new Semaphore(1);
  private Semaphore barSemaphore = new Semaphore(0);
}
