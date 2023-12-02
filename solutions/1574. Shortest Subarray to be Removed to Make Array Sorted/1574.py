class Solution:
  def findLengthOfShortestSubarray(self, arr: List[int]) -> int:
    n = len(arr)
    l = 0
    r = n - 1

    # arr[0..l] is non-decreasing.
    while l < n - 1 and arr[l + 1] >= arr[l]:
      l += 1
    # arr[r..n - 1] is non-decreasing.
    while r > 0 and arr[r - 1] <= arr[r]:
      r -= 1
    # Remove arr[l + 1..n - 1] or arr[0..r - 1].
    ans = min(n - 1 - l, r)

    # Since arr[0..l] and arr[r..n - 1] are non-decreasing, we place pointers
    # at the rightmost indices, l and n - 1, and greedily shrink them toward
    # the leftmost indices, 0 and r, respectively. By removing arr[i + 1..j],
    # we ensure that `arr` becomes non-decreasing.
    i = l
    j = n - 1
    while i >= 0 and j >= r and j > i:
      if arr[i] <= arr[j]:
        j -= 1
      else:
        i -= 1
      ans = min(ans, j - i)

    return ans
