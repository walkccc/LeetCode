class Solution:
  def slowestKey(self, releaseTimes: list[int], keysPressed: str) -> str:
    ans = keysPressed[0]
    maxDuration = releaseTimes[0]

    for i in range(1, len(keysPressed)):
      duration = releaseTimes[i] - releaseTimes[i-1]
      if duration > maxDuration or (
              duration == maxDuration and keysPressed[i] > ans):
        ans = keysPressed[i]
        maxDuration = duration

    return ans
