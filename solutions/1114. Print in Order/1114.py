from threading import Lock


class Foo:
  def __init__(self):
    self.mutex2 = Lock()
    self.mutex3 = Lock()
    self.mutex2.acquire()
    self.mutex3.acquire()

  def first(self, printFirst: 'Callable[[], None]') -> None:
    printFirst()
    self.mutex2.release()

  def second(self, printSecond: 'Callable[[], None]') -> None:
    self.mutex2.acquire()
    printSecond()
    self.mutex3.release()

  def third(self, printThird: 'Callable[[], None]') -> None:
    self.mutex3.acquire()
    printThird()
