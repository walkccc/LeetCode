class Solution:
  def countSteppingNumbers(self, low: int, high: int) -> list[int]:
    ans = [0] if low == 0 else []
    q = collections.deque(list(range(1, 10)))

    while q:
      curr = q.popleft()
      if curr > high:
        continue
      if curr >= low:
        ans.append(curr)
      lastDigit = curr % 10
      if lastDigit > 0:
        q.append(curr * 10 + lastDigit - 1)
      if lastDigit < 9:
        q.append(curr * 10 + lastDigit + 1)

    return ans
