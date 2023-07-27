class Solution:
  def maxVowels(self, s: str, k: int) -> int:
    ans = 0
    maxi = 0
    kVowels = 'aeiou'

    for i, c in enumerate(s):
      if c in kVowels:
        maxi += 1
      if i >= k and s[i - k] in kVowels:
        maxi -= 1
      ans = max(ans, maxi)

    return ans
