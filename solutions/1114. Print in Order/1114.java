class Foo {
  public void first(Runnable printFirst) throws InterruptedException {
    printFirst.run();
    firstDone.incrementAndGet();
  }

  public void second(Runnable printSecond) throws InterruptedException {
    while (firstDone.get() != 1)
      ;
    printSecond.run();
    secondDone.incrementAndGet();
  }

  public void third(Runnable printThird) throws InterruptedException {
    while (secondDone.get() != 1)
      ;
    printThird.run();
  }

  private AtomicInteger firstDone = new AtomicInteger();
  private AtomicInteger secondDone = new AtomicInteger();
}
