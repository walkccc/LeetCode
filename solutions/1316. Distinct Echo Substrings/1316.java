class Solution {
  public int distinctEchoSubstrings(String text) {
    Set<String> seen = new HashSet<>();

    for (int k = 1; k <= text.length() / 2; ++k) { // target length
      int same = 0;
      for (int l = 0, r = k; r < text.length(); ++l, ++r) {
        if (text.charAt(l) == text.charAt(r))
          ++same;
        else
          same = 0;
        if (same == k) {
          seen.add(text.substring(l - k + 1, l + 1));
          // move the window thus leaving a char behind,
          // so we need to decrease the counter
          --same;
        }
      }
    }

    return seen.size();
  }
}
