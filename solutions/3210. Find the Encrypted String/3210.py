class Solution:
  def getEncryptedString(self, s: str, k: int) -> str:
    k %= len(s)
    return s[k:] + s[0:k]
