class Solution:
  # Similar to 300. Longest Increasing Subsequence
  def longestObstacleCourseAtEachPosition(
      self, obstacles: list[int],
  ) -> list[int]:
    ans = []
    # tails[i] := the minimum tail of all the increasing subsequences having
    # length i + 1
    tails = []

    for obstacle in obstacles:
      if not tails or obstacle >= tails[-1]:
        tails.append(obstacle)
        ans.append(len(tails))
      else:
        index = bisect.bisect_right(tails, obstacle)
        tails[index] = obstacle
        ans.append(index + 1)

    return ans
