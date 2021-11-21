class Solution:
  def videoStitching(self, clips: List[List[int]], T: int) -> int:
    ans = 0
    end = 0
    farthest = 0

    clips.sort()

    i = 0
    while farthest < T:
      while i < len(clips) and clips[i][0] <= end:
        farthest = max(farthest, clips[i][1])
        i += 1
      if end == farthest:
        return -1
      ans += 1
      end = farthest

    return ans
