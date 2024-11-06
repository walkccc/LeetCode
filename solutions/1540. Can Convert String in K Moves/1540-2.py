class Solution:
  def canConvertString(self, s: str, t: str, k: int) -> bool:
    if len(s) != len(t):
      return False

    # e.g. s = "aab", t = "bbc", so shiftCount[1] = 3
    # 1. a -> b, need 1 move.
    # 2. a -> b, need 1 + 26 moves.
    # 3. b -> c, need 1 + 26 * 2 moves.
    shiftCount = [0] * 26

    for a, b in zip(s, t):
      shift = (ord(b) - ord(a) + 26) % 26
      if shift == 0:
        continue
      if shift + 26 * shiftCount[shift] > k:
        return False
      shiftCount[shift] += 1

    return True
