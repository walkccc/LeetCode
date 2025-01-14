class Solution:
  def fixedRatio(self, s: str, num1: int, num2: int) -> int:
    # Let x := the number of 0s and y := the number of 1s in the subarray.
    # We want x : y = num1 : num2, so our goal is to find number of subarrays
    # with x * num2 - y * num1 = 0. To achieve this, we can use a prefix count
    # map to record the count of the running x * num2 - y * num1. If the
    # running x * num2 - y * num1 = prefix, then add count[prefix] to the
    # `ans`.
    ans = 0
    prefix = 0
    prefixCount = collections.Counter({0: 1})

    for c in s:
      if c == '0':
        prefix += num2
      else:  # c == '1'
        prefix -= num1
      ans += prefixCount[prefix]
      prefixCount[prefix] += 1

    return ans
