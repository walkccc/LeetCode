class Solution:
  def similarPairs(self, words: list[str]) -> int:
    return sum(set(words[i]) == set(words[j])
               for i in range(len(words))
               for j in range(i + 1, len(words)))
