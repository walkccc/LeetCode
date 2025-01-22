class Solution:
  # Similar to 1736. Latest Time by Replacing Hidden Digits
  def findLatestTime(self, s: str) -> str:
    ans = list(s)
    if s[0] == '?':
      ans[0] = '1' if s[1] == '?' or s[1] < '2' else '0'
    if s[1] == '?':
      ans[1] = '1' if ans[0] == '1' else '9'
    if s[3] == '?':
      ans[3] = '5'
    if s[4] == '?':
      ans[4] = '9'
    return ''.join(ans)
