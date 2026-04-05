class Solution:
  def maximumHappinessSum(self, happiness: list[int], k: int) -> int:
    ans = 0
    decremented = 0

    happiness.sort(reverse=True)

    for i in range(k):
      ans += max(0, happiness[i] - decremented)
      decremented += 1

    return ans
