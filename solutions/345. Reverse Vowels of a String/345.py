class Solution:
  def reverseVowels(self, s: str) -> str:
    chars = list(s)
    kVowels = 'aeiouAEIOU'
    l = 0
    r = len(s) - 1

    while l < r:
      while l < r and chars[l] not in kVowels:
        l += 1
      while l < r and chars[r] not in kVowels:
        r -= 1
      chars[l], chars[r] = chars[r], chars[l]
      l += 1
      r -= 1

    return ''.join(chars)
