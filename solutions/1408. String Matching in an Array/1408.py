class Solution:
  def stringMatching(self, words: list[str]) -> list[str]:
    ans = []
    for a in words:
      for b in words:
        if len(a) < len(b) and b.find(a) != -1:
          ans.append(a)
          break
    return ans
