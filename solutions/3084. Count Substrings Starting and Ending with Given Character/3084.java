class Solution {
  public long countSubstrings(String s, char c) {
    final long freq = s.chars().filter(ch -> ch == c).count();
    return freq * (freq + 1) / 2;
  }
}
