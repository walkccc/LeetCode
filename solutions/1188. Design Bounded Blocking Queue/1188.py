from threading import Semaphore


class BoundedBlockingQueue:
  def __init__(self, capacity: int):
    self.q = collections.deque()
    self.enqueueSemaphore = Semaphore(capacity)
    self.dequeueSemaphore = Semaphore(0)

  def enqueue(self, element: int) -> None:
    self.enqueueSemaphore.acquire()
    self.q.append(element)
    self.dequeueSemaphore.release()

  def dequeue(self) -> int:
    self.dequeueSemaphore.acquire()
    element = self.q.popleft()
    self.enqueueSemaphore.release()
    return element

  def size(self) -> int:
    return len(self.q)
