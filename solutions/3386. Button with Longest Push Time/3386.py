class Solution:
  def buttonWithLongestTime(self, events: list[list[int]]) -> int:
    ans = 0
    maxTimeTaken = 0
    prevTime = 0

    for index, time in events:
      timeTaken = time - prevTime
      if timeTaken > maxTimeTaken or timeTaken == maxTimeTaken and index < ans:
        maxTimeTaken = timeTaken
        ans = index
      prevTime = time

    return ans
