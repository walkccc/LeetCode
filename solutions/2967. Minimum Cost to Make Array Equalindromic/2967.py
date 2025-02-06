class Solution:
  def minimumCost(self, nums: list[int]) -> int:
    nums.sort()
    median = nums[len(nums) // 2]
    nextPalindrome = self._getPalindrome(median, delta=1)
    prevPalindrome = self._getPalindrome(median, delta=-1)
    return min(self._cost(nums, nextPalindrome),
               self._cost(nums, prevPalindrome))

  def _cost(self, nums: list[int], palindrome: int) -> int:
    """Returns the cost to change all the numbers to `palindrome`."""
    return sum(abs(palindrome - num) for num in nums)

  def _getPalindrome(self, num: int, delta: int) -> int:
    """Returns the palindrome `p`, where p = num + a * delta and a > 0."""
    while not self._isPalindrome(num):
      num += delta
    return num

  def _isPalindrome(self, num: int) -> int:
    original = str(num)
    return original == original[::-1]
