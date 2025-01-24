class Solution:
  def findPermutation(self, s: str) -> list[int]:
    ans = [i for i in range(1, len(s) + 2)]

    # For each D* group (s[i..j]), reverse ans[i..j + 1].
    i = -1
    j = -1

    def getNextIndex(c: str, start: int) -> int:
      for i in range(start, len(s)):
        if s[i] == c:
          return i
      return len(s)

    while True:
      i = getNextIndex('D', j + 1)
      if i == len(s):
        break
      j = getNextIndex('I', i + 1)
      ans[i:j + 1] = ans[i:j + 1][::-1]

    return ans
