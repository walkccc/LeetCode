class Solution {
  public boolean hasMatch(String s, String p) {
    final int starPos = p.indexOf('*');
    final String prefix = p.substring(0, starPos);
    final String suffix = p.substring(starPos + 1);
    final int i = s.indexOf(prefix);
    return i != -1 && s.indexOf(suffix, i + prefix.length()) != -1;
  }
}
