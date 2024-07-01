class Solution {
  public List<String> ambiguousCoordinates(String s) {
    List<String> ans = new ArrayList<>();
    s = s.substring(1, s.length() - 1);

    for (int i = 1; i < s.length(); ++i)
      for (final String x : splits(s.substring(0, i)))
        for (final String y : splits(s.substring(i)))
          ans.add("(" + x + ", " + y + ")");

    return ans;
  }

  private List<String> splits(final String s) {
    if (s.isEmpty() || s.length() > 1 && s.charAt(0) == '0' && s.charAt(s.length() - 1) == '0')
      return new ArrayList<>();
    if (s.charAt(s.length() - 1) == '0')
      return new ArrayList<>(Arrays.asList(s));
    if (s.charAt(0) == '0')
      return new ArrayList<>(Arrays.asList("0." + s.substring(1)));

    List<String> res = new ArrayList<>(Arrays.asList(s));
    for (int i = 1; i < s.length(); ++i)
      res.add(s.substring(0, i) + "." + s.substring(i));
    return res;
  }
}
