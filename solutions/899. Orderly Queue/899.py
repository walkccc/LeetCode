class Solution:
  def orderlyQueue(self, s: str, k: int) -> str:
    return (''.join(sorted(s)) if k > 1
            else min(s[i:] + s[:i] for i in range(len(s))))
