class Solution {
  public boolean isPossibleToRearrange(String s, String t, int k) {
    final int n = s.length();
    return getCount(s, n / k).equals(getCount(t, n / k));
  }

  private Map<String, Integer> getCount(final String s, int sz) {
    Map<String, Integer> count = new HashMap<>();
    for (int i = 0; i < s.length(); i += sz)
      count.merge(s.substring(i, i + sz), 1, Integer::sum);
    return count;
  }
}
