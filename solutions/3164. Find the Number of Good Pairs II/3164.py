class Solution:
  def numberOfPairs(self, nums1: list[int], nums2: list[int], k: int) -> int:
    count = collections.Counter(num * k for num in nums2)
    ans = 0

    for num in nums1:
      for divisor in range(1, int(num ** 0.5) + 1):
        if num % divisor == 0:
          ans += count[divisor]
          if num // divisor != divisor:
            ans += count[num // divisor]

    return ans
