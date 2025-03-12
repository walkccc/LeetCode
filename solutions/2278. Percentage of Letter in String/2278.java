class Solution {
  public int percentageLetter(String s, char letter) {
    return 100 * (int) s.chars().filter(c -> c == letter).count() / s.length();
  }
}
