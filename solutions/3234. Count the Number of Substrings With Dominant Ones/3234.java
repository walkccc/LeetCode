class Solution {
  public int numberOfSubstrings(String s) {
    int ans = 0;

    // Iterate through all possible number of 0s.
    for (int zero = 0; zero + zero * zero <= s.length(); ++zero) {
      int lastInvalidPos = -1;
      int[] count = new int[2];
      for (int l = 0, r = 0; r < s.length(); ++r) {
        ++count[s.charAt(r) - '0'];
        // Try to shrink the window to maintain the "minimum" length of the
        // valid substring.
        for (; l < r; ++l)
          if (s.charAt(l) == '0' && count[0] > zero) {
            --count[0]; // Remove an extra '0'.
            lastInvalidPos = l;
          } else if (s.charAt(l) == '1' && count[1] - 1 >= zero * zero) {
            --count[1]; // Remove an extra '1'.
          } else {
            break; // Cannot remove more characters.
          }
        if (count[0] == zero && count[1] >= zero * zero)
          // Add valid substrings ending in s[r] to the answer. They are
          // s[lastInvalidPos + 1..r], s[lastInvalidPos + 2..r], ..., s[l..r].
          ans += l - lastInvalidPos;
      }
    }

    return ans;
  }
}
