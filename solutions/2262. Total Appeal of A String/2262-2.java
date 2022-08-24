class Solution {
  public long appealSum(String s) {
    long ans = 0;
    int[] lastOccurrence = new int[26];
    Arrays.fill(lastOccurrence, -1);

    for (int i = 0; i < s.length(); ++i) {
      ans += (i - lastOccurrence[s.charAt(i) - 'a']) * (s.length() - i);
      lastOccurrence[s.charAt(i) - 'a'] = i;
    }

    return ans;
  }
}
