class Solution:
  def maxCandies(self, status: List[int], candies: List[int], keys: List[List[int]], containedBoxes: List[List[int]], initialBoxes: List[int]) -> int:
    ans = 0
    q = deque()
    reachedClosedBoxes = [0] * len(status)

    def pushBoxesIfPossible(boxes: List[int]) -> None:
      for box in boxes:
        if status[box]:
          q.append(box)
        else:
          reachedClosedBoxes[box] = True

    pushBoxesIfPossible(initialBoxes)

    while q:
      currBox = q.popleft()

      # add candies
      ans += candies[currBox]

      # push `reachedClosedBoxes` by `key` obtained this turn and change their
      # statuses
      for key in keys[currBox]:
        if not status[key] and reachedClosedBoxes[key]:
          q.append(key)
        status[key] = 1  # boxes[key] is now open

      # push boxes contained in `currBox`
      pushBoxesIfPossible(containedBoxes[currBox])

    return ans
