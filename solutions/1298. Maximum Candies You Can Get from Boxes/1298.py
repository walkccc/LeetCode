class Solution:
  def maxCandies(
      self,
      status: list[int],
      candies: list[int],
      keys: list[list[int]],
      containedBoxes: list[list[int]],
      initialBoxes: list[int],
  ) -> int:
    ans = 0
    q = collections.deque()
    reachedClosedBoxes = [0] * len(status)

    def pushBoxesIfPossible(boxes: list[int]) -> None:
      for box in boxes:
        if status[box]:
          q.append(box)
        else:
          reachedClosedBoxes[box] = True

    pushBoxesIfPossible(initialBoxes)

    while q:
      currBox = q.popleft()

      # Add the candies.
      ans += candies[currBox]

      # Push `reachedClosedBoxes` by `key` obtained in this turn and change
      # their statuses.
      for key in keys[currBox]:
        if not status[key] and reachedClosedBoxes[key]:
          q.append(key)
        status[key] = 1  # boxes[key] is now open

      # Push the boxes contained in `currBox`.
      pushBoxesIfPossible(containedBoxes[currBox])

    return ans
