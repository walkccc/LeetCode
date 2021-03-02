class Foo {
 public:
  Foo() {
    mutex2.lock();
    mutex3.lock();
  }

  void first(function<void()> printFirst) {
    printFirst();
    mutex2.unlock();
  }

  void second(function<void()> printSecond) {
    mutex2.lock();
    printSecond();
    mutex3.unlock();
  }

  void third(function<void()> printThird) {
    mutex3.lock();
    printThird();
  }

 private:
  mutex mutex2;
  mutex mutex3;
};
