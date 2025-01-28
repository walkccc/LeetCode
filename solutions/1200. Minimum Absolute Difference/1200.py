class Solution:
  def minimumAbsDifference(self, arr: list[int]) -> list[list[int]]:
    ans = []
    mn = math.inf

    arr.sort()

    for a, b in itertools.pairwise(arr):
      diff = b - a
      if diff < mn:
        mn = diff
        ans = []
      if diff == mn:
        ans.append([a, b])

    return ans
