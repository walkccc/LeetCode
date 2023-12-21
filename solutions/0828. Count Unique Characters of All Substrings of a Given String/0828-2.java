class Solution {
  public int uniqueLetterString(String s) {
    int n = s.length();
    int ans = 0;
    // lastSeen[c] := the index of the last time ('a' + i) appeared
    int[] lastSeen = new int[26];
    // prevSeen[c] := the previous index of the last time ('a' + i) appeared
    int[] prevLastSeen = new int[26];
    Arrays.fill(lastSeen, -1);
    Arrays.fill(prevLastSeen, -1);

    for (int i = 0; i < n; ++i) {
      final int c = s.charAt(i) - 'A';
      if (lastSeen[c] != -1)
        ans += (i - lastSeen[c]) * (lastSeen[c] - prevLastSeen[c]);
      prevLastSeen[c] = lastSeen[c];
      lastSeen[c] = i;
    }

    for (int c = 0; c < 26; ++c)
      ans += (n - lastSeen[c]) * (lastSeen[c] - prevLastSeen[c]);

    return ans;
  }
}
