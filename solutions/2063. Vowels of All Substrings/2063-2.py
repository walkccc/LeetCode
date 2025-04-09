class Solution:
  def countVowels(self, word: str) -> int:
    return sum((i + 1) * (len(word) - i)
               for i, c in enumerate(word)
               if c in 'aeiou')
