class Solution {
  public List<List<String>> groupStrings(String[] strings) {
    Map<String, List<String>> keyToStrings = new HashMap<>();

    for (final String s : strings)
      keyToStrings.computeIfAbsent(getKey(s), k -> new ArrayList<>()).add(s);

    return new ArrayList<>(keyToStrings.values());
  }

  // Returns the key of 's' by pairwise calculation of differences.
  // e.g. getKey("abc") -> "1,1" because diff(a, b) = 1 and diff(b, c) = 1.
  private String getKey(final String s) {
    StringBuilder sb = new StringBuilder();

    for (int i = 1; i < s.length(); ++i) {
      final int diff = (s.charAt(i) - s.charAt(i - 1) + 26) % 26;
      sb.append(diff).append(",");
    }

    return sb.toString();
  }
}
