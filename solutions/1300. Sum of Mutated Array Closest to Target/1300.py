class Solution:
  def findBestValue(self, arr: List[int], target: int) -> int:
    prefix = 0

    arr.sort()

    for i, a in enumerate(arr):
      ans = round((target - prefix) / (len(arr) - i))
      if ans <= a:
        return ans
      prefix += a

    return arr[-1]
