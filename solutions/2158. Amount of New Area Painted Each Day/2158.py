from sortedcontainers import SortedList


class Solution:
  def amountPainted(self, paint: List[List[int]]) -> List[int]:
    minDay = min(s for s, e in paint)
    maxDay = max(e for s, e in paint)
    ans = [0] * len(paint)
    # Stores the indices of paints that are available now.
    runningIndices = SortedList()
    events = []  # (day, index, type)

    for i, (start, end) in enumerate(paint):
      events.append((start, i, 1))  # 1 := entering
      events.append((end, i, -1))  # -1 := leaving

    events.sort()

    i = 0  # events' index
    for day in range(minDay, maxDay):
      while i < len(events) and events[i][0] == day:
        day, index, type = events[i]
        if type == 1:
          runningIndices.add(index)
        else:
          runningIndices.remove(index)
        i += 1
      if runningIndices:
        ans[runningIndices[0]] += 1

    return ans
