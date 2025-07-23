class Solution:
  def countBeautifulPairs(self, nums: list[int]) -> int:
    def firstDigit(num: int) -> int:
      return int(str(num)[0])

    def lastDigit(num: int) -> int:
      return num % 10

    return sum(math.gcd(firstDigit(nums[i]), lastDigit(nums[j])) == 1
               for i, j in itertools.combinations(range(len(nums)), 2))
