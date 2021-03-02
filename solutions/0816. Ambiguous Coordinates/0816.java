class Solution {
  public List<String> ambiguousCoordinates(String S) {
    List<String> ans = new ArrayList<>();
    S = S.substring(1, S.length() - 1);

    for (int i = 1; i < S.length(); ++i)
      for (final String x : splits(S.substring(0, i)))
        for (final String y : splits(S.substring(i)))
          ans.add("(" + x + ", " + y + ")");

    return ans;
  }

  private List<String> splits(final String S) {
    if (S.isEmpty() || S.length() > 1 && S.charAt(0) == '0' && S.charAt(S.length() - 1) == '0')
      return new ArrayList<>();
    if (S.charAt(S.length() - 1) == '0')
      return new ArrayList<>(Arrays.asList(S));
    if (S.charAt(0) == '0')
      return new ArrayList<>(Arrays.asList("0." + S.substring(1)));

    List<String> res = new ArrayList<>(Arrays.asList(S));
    for (int i = 1; i < S.length(); ++i)
      res.add(S.substring(0, i) + "." + S.substring(i));
    return res;
  }
}
