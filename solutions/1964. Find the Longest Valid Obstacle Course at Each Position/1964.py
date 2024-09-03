class Solution:
  # Similar to 300. Longest Increasing Subsequence
  def longestObstacleCourseAtEachPosition(
      self, obstacles: list[int],
  ) -> list[int]:
    ans = []
    # tail[i] := the minimum tail of all the increasing subsequences having
    # length i + 1
    tail = []

    for obstacle in obstacles:
      if not tail or obstacle >= tail[-1]:
        tail.append(obstacle)
        ans.append(len(tail))
      else:
        index = bisect.bisect_right(tail, obstacle)
        tail[index] = obstacle
        ans.append(index + 1)

    return ans
