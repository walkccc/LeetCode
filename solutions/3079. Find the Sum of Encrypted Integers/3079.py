class Solution:
  def sumOfEncryptedInt(self, nums: list[int]) -> int:
    def getEncrypted(num: int) -> int:
      maxDigit = 0
      base = 0
      while num > 0:
        maxDigit = max(maxDigit, num % 10)
        base = base * 10 + 1
        num //= 10
      return base * maxDigit

    return sum(getEncrypted(num) for num in nums)
