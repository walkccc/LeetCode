class Solution:
  def makeSubKSumEqual(self, arr: list[int], k: int) -> int:
    # If the sum of each subarray of length k is equal, then `arr` must have a
    # repeated pattern of size k. e.g. arr = [1, 2, 3, ...] and k = 3, to have
    # sum([1, 2, 3)] == sum([2, 3, x]), x must be 1. Therefore, arr[i] ==
    # arr[(i + k) % n] for every i.
    n = len(arr)
    ans = 0
    seen = [0] * n

    for i in range(n):
      groups = []
      j = i
      while not seen[j]:
        groups.append(arr[j])
        seen[j] = True
        j = (j + k) % n
      groups.sort()
      for num in groups:
        ans += abs(num - groups[len(groups) // 2])

    return ans
