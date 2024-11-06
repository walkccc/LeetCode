class Solution:
  def hasAllCodes(self, s: str, k: int) -> bool:
    n = 1 << k
    if len(s) < n:
      return False

    # used[i] := True if i is a substring of `s`
    used = [0] * n

    windowStr = 0 if k == 1 else int(s[0:k - 1], 2)
    for i in range(k - 1, len(s)):
      # Include the s[i].
      windowStr = (windowStr << 1) + int(s[i])
      # Discard the s[i - k].
      windowStr &= n - 1
      used[windowStr] = True

    return all(u for u in used)
