public class Solution {
  public String minimumString(String a, String b, String c) {
    final String abc = merge(a, merge(b, c));
    final String acb = merge(a, merge(c, b));
    final String bac = merge(b, merge(a, c));
    final String bca = merge(b, merge(c, a));
    final String cab = merge(c, merge(a, b));
    final String cba = merge(c, merge(b, a));
    return getMin(Arrays.asList(abc, acb, bac, bca, cab, cba));
  }

  // Merges a and b.
  private String merge(String a, String b) {
    if (b.contains(a)) // a is a substring of b.
      return b;
    for (int i = 0; i < a.length(); ++i) {
      final String aSuffix = a.substring(i);
      final String bPrefix = b.substring(0, Math.min(b.length(), aSuffix.length()));
      if (aSuffix.equals(bPrefix))
        return a + b.substring(bPrefix.length());
    }
    return a + b;
  }

  // Returns the lexicographically smallest string.
  private String getMin(List<String> words) {
    String res = words.get(0);
    for (int i = 1; i < words.size(); ++i)
      res = getMin(res, words.get(i));
    return res;
  }

  // Returns the lexicographically smaller string.
  private String getMin(String a, String b) {
    return (a.length() < b.length() || (a.length() == b.length() && a.compareTo(b) < 0)) ? a : b;
  }
}
