class Solution:
  def containsPattern(self, arr: list[int], m: int, k: int) -> bool:
    count = 0
    for i in range(m, len(arr)):
      count = count + 1 if arr[i] == arr[i - m] else 0
      if count == m * k - m:
        return True
    return False
