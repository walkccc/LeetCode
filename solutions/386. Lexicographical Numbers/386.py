class Solution:
  def lexicalOrder(self, n: int) -> list[int]:
    ans = []
    curr = 1

    while len(ans) < n:
      ans.append(curr)
      if curr * 10 <= n:
        curr *= 10
      else:
        while curr % 10 == 9 or curr == n:
          curr //= 10
        curr += 1

    return ans
