class Solution {
  public boolean canBeEqual(String s1, String s2) {
    for (final String a : swappedStrings(s1))
      for (final String b : swappedStrings(s2))
        if (a.equals(b))
          return true;
    return false;
  }

  private List<String> swappedStrings(final String s) {
    List<String> res = new ArrayList<>();
    char[] chars = s.toCharArray();
    res.add(s);
    res.add(new String(new char[] {chars[2], chars[1], chars[0], chars[3]}));
    res.add(new String(new char[] {chars[0], chars[3], chars[2], chars[1]}));
    res.add(new String(new char[] {chars[2], chars[3], chars[0], chars[1]}));
    return res;
  }
}
