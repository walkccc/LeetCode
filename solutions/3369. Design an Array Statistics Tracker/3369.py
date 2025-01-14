from sortedcontainers import SortedList


class StatisticsTracker:
  def __init__(self):
    self.q = collections.deque()
    self.count = collections.Counter()
    self.sortedList = SortedList()
    self.modeMaxHeap = []  # (frequency, number)
    self.sum = 0

  def addNumber(self, number: int) -> None:
    self.q.append(number)
    self.count[number] += 1
    self.sortedList.add(number)
    heapq.heappush(self.modeMaxHeap, (-self.count[number], number))
    self.sum += number

  def removeFirstAddedNumber(self) -> None:
    number = self.q.popleft()
    self.count[number] -= 1
    self.sortedList.remove(number)
    # Note: No need to update the heap now; we'll clean up stale entries when
    # getting the mode.
    self.sum -= number

  def getMean(self) -> int:
    return self.sum // len(self.q)

  def getMedian(self) -> int:
    return self.sortedList[len(self.sortedList) // 2]

  def getMode(self) -> int:
    # Removes stale heap entries where frequency no longer matches.
    while self.modeMaxHeap:
      frequency = -self.modeMaxHeap[0][0]
      number = self.modeMaxHeap[0][1]
      if self.count[number] == frequency:
        return number
      heapq.heappop(self.modeMaxHeap)
