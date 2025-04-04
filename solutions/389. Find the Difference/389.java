class Solution {
  public char findTheDifference(String s, String t) {
    final char sXors = (char) s.chars().reduce(0, (a, b) -> a ^ b);
    final char tXors = (char) t.chars().reduce(0, (a, b) -> a ^ b);
    return (char) (sXors ^ tXors);
  }
}
