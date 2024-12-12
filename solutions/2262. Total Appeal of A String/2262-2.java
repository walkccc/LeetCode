class Solution {
  public long appealSum(String s) {
    final int n = s.length();
    long ans = 0;
    int[] lastSeen = new int[26];
    Arrays.fill(lastSeen, -1);

    for (int i = 0; i < n; ++i) {
      final int c = s.charAt(i) - 'a';
      ans += (i - lastSeen[c]) * (n - i);
      lastSeen[c] = i;
    }

    return ans;
  }
}
