class Solution:
  def replaceNonCoprimes(self, nums: List[int]) -> List[int]:
    ans = []

    for num in nums:
      while ans and gcd(ans[-1], num) > 1:
        num = lcm(ans.pop(), num)
      ans.append(num)

    return ans
