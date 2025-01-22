class Solution:
  def nextGreaterElement(self, n: int) -> int:
    def nextPermutation(s: list[str]) -> str:
      i = len(s) - 2
      while i >= 0:
        if s[i] < s[i + 1]:
          break
        i -= 1

      if i >= 0:
        for j in range(len(s) - 1, i, -1):
          if s[j] > s[i]:
            break
        s[i], s[j] = s[j], s[i]

      reverse(s, i + 1, len(s) - 1)
      return ''.join(s)

    def reverse(s: list[str], l: int, r: int):
      while l < r:
        s[l], s[r] = s[r], s[l]
        l += 1
        r -= 1

    s = nextPermutation(list(str(n)))
    ans = int(s)
    return -1 if ans > 2**31 - 1 or ans <= n else ans
