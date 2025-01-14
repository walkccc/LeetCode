class Solution:
  def isValid(self, word: str) -> bool:
    kVowels = 'aeiouAEIOU'

    def isConsonant(c: str) -> bool:
      return c.isalpha() and c not in kVowels

    return (len(word) >= 3 and
            all(c.isalnum() for c in word) and
            any(c in kVowels for c in word) and
            any(isConsonant(c) for c in word))
