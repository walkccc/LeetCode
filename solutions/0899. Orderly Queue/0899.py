class Solution:
  def orderlyQueue(self, S: str, K: int) -> str:
    return ''.join(sorted(S)) if K > 1 else min(S[i:] + S[:i] for i in range(len(S)))
