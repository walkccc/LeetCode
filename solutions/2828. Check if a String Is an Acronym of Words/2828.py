class Solution:
  def isAcronym(self, words: List[str], s: str) -> bool:
    return len(words) == len(s) and \
        all(word[0] == c for word, c in zip(words, s))
