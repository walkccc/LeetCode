class Solution:
  def numberOfSubstrings(self, s: str) -> int:
    ans = 0
    #    z^2 + z = n.
    # => z^2 + z - n = 0.
    # => z = (-1 + sqrt(1 + 4n)) / 2.
    maxZero = (-1 + math.sqrt(1 + 4 * len(s))) // 2

    # Iterate through all possible number of 0s.
    for zero in range(int(maxZero) + 1):
      lastInvalidPos = -1
      count = [0, 0]
      l = 0
      for r, c in enumerate(s):
        count[int(c)] += 1
        # Try to shrink the window to maintain the "minimum" length of the
        # valid substring.
        while l < r:
          if s[l] == '0' and count[0] > zero:
            count[0] -= 1  # Remove an extra '0'.
            lastInvalidPos = l
            l += 1
          elif s[l] == '1' and count[1] - 1 >= zero * zero:
            count[1] -= 1  # Remove an extra '1'.
            l += 1
          else:
            break  # Cannot remove more characters.
        if count[0] == zero and count[1] >= zero * zero:
          # Add valid substrings ending in s[r] to the answer. They are
          # s[lastInvalidPos + 1..r], s[lastInvalidPos + 2..r], ..., s[l..r].
          ans += l - lastInvalidPos

    return ans
