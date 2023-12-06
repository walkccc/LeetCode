class Solution:
  def countSteppingNumbers(self, low: int, high: int) -> List[int]:
    ans = [0] if low == 0 else []

    def dfs(curr: int) -> None:
      if curr > high:
        return
      if curr >= low:
        ans.append(curr)

      lastDigit = curr % 10
      if lastDigit > 0:
        dfs(curr * 10 + lastDigit - 1)
      if lastDigit < 9:
        dfs(curr * 10 + lastDigit + 1)

    for i in range(1, 9 + 1):
      dfs(i)

    ans.sort()
    return ans
