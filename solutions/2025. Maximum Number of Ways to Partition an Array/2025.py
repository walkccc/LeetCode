class Solution:
  def waysToPartition(self, nums: List[int], k: int) -> int:
    n = len(nums)
    summ = sum(nums)
    prefix = 0
    l = Counter()  # count of sum(A[0..k)) - sum(A[k..n)) for k in [0..i)
    r = Counter()  # count of sum(A[0..k)) - sum(A[k..n)) for k in [i..n)

    for pivot in range(1, n):
      prefix += nums[pivot - 1]
      suffix = summ - prefix
      r[prefix - suffix] += 1

    ans = r[0]
    prefix = 0

    for num in nums:
      ans = max(ans, l[k - num] + r[num - k])
      prefix += num
      suffix = summ - prefix
      diff = prefix - suffix
      r[diff] -= 1
      l[diff] += 1

    return ans
