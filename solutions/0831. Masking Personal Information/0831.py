class Solution:
  def maskPII(self, S: str) -> str:
    atIndex = S.find('@')
    if atIndex != -1:
      S = S.lower()
      return S[0] + '*' * 5 + S[atIndex - 1:]

    ans = ''.join(c for c in S if c.isdigit())

    if len(ans) == 10:
      return '***-***-' + ans[-4:]
    return '+' + '*' * (len(ans) - 10) + '-***-***-' + ans[-4:]
