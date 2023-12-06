class Solution:
  def halvesAreAlike(self, s: str) -> bool:
    kVowels = 'aeiouAEIOU'
    aVowelsCount = sum(c in kVowels for c in s[:len(s) // 2])
    bVowelsCount = sum(c in kVowels for c in s[len(s) // 2:])
    return aVowelsCount == bVowelsCount
