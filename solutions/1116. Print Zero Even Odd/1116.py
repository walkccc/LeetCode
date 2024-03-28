from threading import Semaphore


class ZeroEvenOdd:
  def __init__(self, n):
    self.n = n
    self.zeroSemaphore = Semaphore(1)
    self.evenSemaphore = Semaphore(0)
    self.oddSemaphore = Semaphore(0)

  # printNumber(x) outputs "x", where x is an integer.
  def zero(self, printNumber: 'Callable[[int], None]') -> None:
    for i in range(self.n):
      self.zeroSemaphore.acquire()
      printNumber(0)
      (self.oddSemaphore if i & 2 == 0 else self.evenSemaphore).release()

  def even(self, printNumber: 'Callable[[int], None]') -> None:
    for i in range(2, self.n + 1, 2):
      self.evenSemaphore.acquire()
      printNumber(i)
      self.zeroSemaphore.release()

  def odd(self, printNumber: 'Callable[[int], None]') -> None:
    for i in range(1, self.n + 1, 2):
      self.oddSemaphore.acquire()
      printNumber(i)
      self.zeroSemaphore.release()
