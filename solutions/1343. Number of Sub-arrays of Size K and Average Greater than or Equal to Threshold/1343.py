class Solution:
  def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
    ans = 0
    windowSum = 0

    for i in range(len(arr)):
      windowSum += arr[i]
      if i >= k:
        windowSum -= arr[i - k]
      if i >= k - 1 and windowSum // k >= threshold:
        ans += 1

    return ans
