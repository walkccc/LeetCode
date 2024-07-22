class Solution:
  def licenseKeyFormatting(self, s: str, k: int) -> str:
    ans = []
    length = 0

    for i in reversed(range(len(s))):
      if s[i] == '-':
        continue
      if length > 0 and length % k == 0:
        ans += '-'
      ans += s[i].upper()
      length += 1

    return ''.join(reversed(ans))
