class Solution:
  def validWordSquare(self, words: list[str]) -> bool:
    for i, word in enumerate(words):
      for j, c in enumerate(word):
        if len(words) <= j or len(words[j]) <= i:  # out-of-bounds
          return False
        if c != words[j][i]:
          return False
    return True
