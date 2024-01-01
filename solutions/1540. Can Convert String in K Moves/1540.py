class Solution:
  def canConvertString(self, s: str, t: str, k: int) -> bool:
    if len(s) != len(t):
      return False

    # e.g. s = "aab", t = "bbc", so shiftCount[1] = 3
    # Case 1: a -> b, need 1 move.
    # Case 2: a -> b, need 1 + 26 moves.
    # Case 3: b -> c, need 1 + 26 * 2 moves.
    shiftCount = [0] * 26

    for a, b in zip(s, t):
      shiftCount[(ord(b) - ord(a) + 26) % 26] += 1

    for shift in range(1, 26):
      if shift + 26 * (shiftCount[shift] - 1) > k:
        return False

    return True
