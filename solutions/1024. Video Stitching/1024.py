class Solution:
  def videoStitching(self, clips: list[list[int]], time: int) -> int:
    ans = 0
    end = 0
    farthest = 0

    clips.sort()

    i = 0
    while farthest < time:
      while i < len(clips) and clips[i][0] <= end:
        farthest = max(farthest, clips[i][1])
        i += 1
      if end == farthest:
        return -1
      ans += 1
      end = farthest

    return ans
