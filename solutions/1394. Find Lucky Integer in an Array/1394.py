class Solution:
  def findLucky(self, arr: list[int]) -> int:
    count = [0] * (len(arr) + 1)

    for a in arr:
      if a <= len(arr):
        count[a] += 1

    for i in range(len(arr), 0, -1):
      if count[i] == i:
        return i

    return -1
