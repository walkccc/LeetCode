class Foo {
 public:
  Foo() {
    firstDone.lock();
    secondDone.lock();
  }

  void first(function<void()> printFirst) {
    printFirst();
    firstDone.unlock();
  }

  void second(function<void()> printSecond) {
    firstDone.lock();
    printSecond();
    secondDone.unlock();
  }

  void third(function<void()> printThird) {
    secondDone.lock();
    printThird();
  }

 private:
  mutex firstDone;
  mutex secondDone;
};
