class Solution {
  public int minimizedStringLength(String s) {
    return new HashSet<>(Arrays.asList(s.split(""))).size();
  }
}
