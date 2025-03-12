class Solution:
  def halvesAreAlike(self, s: str) -> bool:
    VOWELS = 'aeiouAEIOU'
    aVowelsCount = sum(c in VOWELS for c in s[:len(s) // 2])
    bVowelsCount = sum(c in VOWELS for c in s[len(s) // 2:])
    return aVowelsCount == bVowelsCount
