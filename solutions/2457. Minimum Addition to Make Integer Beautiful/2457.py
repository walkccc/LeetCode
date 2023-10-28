class Solution:
  def makeIntegerBeautiful(self, n: int, target: int) -> int:
    ans = 0
    power = 1

    # E.g., n = 123. After tunning off the last bit by adding 7, n = 130,
    # effectively, we can think n as 13. That's why we do n = (n / 10) + 1.
    while sum(map(int, str(n))) > target:
      # Cost to turn off last digit.
      ans += power * (10 - n % 10)
      n = n // 10 + 1
      power *= 10

    return ans
