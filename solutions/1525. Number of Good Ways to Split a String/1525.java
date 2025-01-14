class Solution {
  public int numSplits(String s) {
    final int n = s.length();
    int ans = 0;
    int[] prefix = new int[n];
    int[] suffix = new int[n];
    Set<Character> seen = new HashSet<>();

    for (int i = 0; i < n; ++i) {
      seen.add(s.charAt(i));
      prefix[i] = seen.size();
    }

    seen.clear();

    for (int i = n - 1; i >= 0; --i) {
      seen.add(s.charAt(i));
      suffix[i] = seen.size();
    }

    for (int i = 0; i + 1 < n; ++i)
      if (prefix[i] == suffix[i + 1])
        ++ans;

    return ans;
  }
}
