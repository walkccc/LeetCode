class Solution {
  public int minSteps(String s, String t) {
    int[] count = new int[26];
    s.chars().forEach(c -> ++count[c - 'a']);
    t.chars().forEach(c -> --count[c - 'a']);
    return Arrays.stream(count).map(Math::abs).sum();
  }
}
