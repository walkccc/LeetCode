from threading import Lock


class Foo:
  def __init__(self):
    self.firstDone = Lock()
    self.secondDone = Lock()
    self.firstDone.acquire()
    self.secondDone.acquire()

  def first(self, printFirst: 'Callable[[], None]') -> None:
    printFirst()
    self.firstDone.release()

  def second(self, printSecond: 'Callable[[], None]') -> None:
    self.firstDone.acquire()
    printSecond()
    self.secondDone.release()

  def third(self, printThird: 'Callable[[], None]') -> None:
    self.secondDone.acquire()
    printThird()
