class Solution:
  def trimMean(self, arr: list[int]) -> float:
    arr.sort()
    offset = len(arr) // 20
    return mean(arr[offset:-offset])
