class Solution:
  def maxVowels(self, s: str, k: int) -> int:
    ans = 0
    mx = 0
    kVowels = 'aeiou'

    for i, c in enumerate(s):
      if c in kVowels:
        mx += 1
      if i >= k and s[i - k] in kVowels:
        mx -= 1
      ans = max(ans, mx)

    return ans
