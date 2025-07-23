class Solution:
  def maxVowels(self, s: str, k: int) -> int:
    ans = 0
    mx = 0
    VOWELS = 'aeiou'

    for i, c in enumerate(s):
      if c in VOWELS:
        mx += 1
      if i >= k and s[i - k] in VOWELS:
        mx -= 1
      ans = max(ans, mx)

    return ans
