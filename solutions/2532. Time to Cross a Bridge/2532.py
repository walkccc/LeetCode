class Solution:
  def findCrossingTime(self, n: int, k: int, time: list[list[int]]) -> int:
    ans = 0
    # (leftToRight + rightToLeft, i)
    leftBridgeQueue = [
        (-leftToRight - rightToLeft, -i) for i,
        (leftToRight, pickOld, rightToLeft, pickNew) in enumerate(time)]
    rightBridgeQueue = []
    # (time to be idle, i)
    leftWorkers = []
    rightWorkers = []

    heapq.heapify(leftBridgeQueue)

    while n > 0 or rightBridgeQueue or rightWorkers:
      # Idle left workers get on the left bridge.
      while leftWorkers and leftWorkers[0][0] <= ans:
        i = heapq.heappop(leftWorkers)[1]
        leftWorkers.pop()
        heapq.heappush(leftBridgeQueue, (-time[i][0] - time[i][2], -i))
      # Idle right workers get on the right bridge.
      while rightWorkers and rightWorkers[0][0] <= ans:
        i = heapq.heappop(rightWorkers)[1]
        heapq.heappush(rightBridgeQueue, (-time[i][0] - time[i][2], -i))
      if rightBridgeQueue:
        # If the bridge is free, the worker waiting on the right side of the
        # bridge gets to cross the bridge. If more than one worker is waiting
        # on the right side, the one with the lowest efficiency crosses first.
        i = -heapq.heappop(rightBridgeQueue)[1]
        ans += time[i][2]
        heapq.heappush(leftWorkers, (ans + time[i][3], i))
      elif leftBridgeQueue and n > 0:
        # If the bridge is free and no worker is waiting on the right side, and
       # at least one box remains at the old warehouse, the worker on the left
       # side of the river gets to cross the bridge. If more than one worker
       # is waiting on the left side, the one with the lowest efficiency
       # crosses first.
        i = -heapq.heappop(leftBridgeQueue)[1]
        ans += time[i][0]
        heapq.heappush(rightWorkers, (ans + time[i][1], i))
        n -= 1
      else:
        # Advance the time of the last crossing worker.
        ans = min(leftWorkers[0][0] if leftWorkers and n > 0 else math.inf,
                  rightWorkers[0][0] if rightWorkers else math.inf)

    return ans
