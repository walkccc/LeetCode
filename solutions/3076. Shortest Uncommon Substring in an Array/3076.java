class Solution {
  public String[] shortestSubstrings(String[] arr) {
    String[] ans = new String[arr.length];
    Map<String, Integer> count = new HashMap<>();

    for (int i = 0; i < arr.length; ++i)
      add(arr[i], count);

    for (int i = 0; i < arr.length; ++i) {
      remove(arr[i], count);
      ans[i] = getMinSub(arr[i], count);
      add(arr[i], count);
    }

    return ans;
  }

  private List<String> getSubstrings(String s) {
    List<String> substrings = new ArrayList<>();
    for (int i = 0; i < s.length(); ++i)
      for (int j = i + 1; j <= s.length(); ++j)
        substrings.add(s.substring(i, j));
    return substrings;
  }

  private void add(final String s, Map<String, Integer> count) {
    for (final String sub : getSubstrings(s))
      count.merge(sub, 1, Integer::sum);
  }

  private void remove(String s, Map<String, Integer> count) {
    for (final String sub : getSubstrings(s))
      count.merge(sub, -1, Integer::sum);
  }

  private String getMinSub(String s, Map<String, Integer> count) {
    String minSub = "";
    for (final String sub : getSubstrings(s)) {
      if (count.get(sub) > 0)
        continue;
      if (minSub.equals("") || sub.length() < minSub.length() ||
          sub.length() == minSub.length() && sub.compareTo(minSub) < 0)
        minSub = sub;
    }
    return minSub;
  }
}
