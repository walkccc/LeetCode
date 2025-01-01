class Solution:
  def numFriendRequests(self, ages: list[int]) -> int:
    ans = 0
    count = [0] * 121

    for age in ages:
      count[age] += 1

    for i in range(15, 121):
      ans += count[i] * (count[i] - 1)

    for i in range(15, 121):
      for j in range(i // 2 + 8, i):
        ans += count[i] * count[j]

    return ans
