class Solution:
  def addMinimum(self, word: str) -> int:
    letters = ['a', 'b', 'c']
    ans = 0
    i = 0

    while i < len(word):
      for c in letters:
        if i < len(word) and word[i] == c:
          i += 1
        else:
          ans += 1

    return ans
