class Solution {
  public int uniqueLetterString(String s) {
    int ans = 0;
    int count = 0;
    int[] lastCount = new int[26];
    int[] lastSeen = new int[26];
    Arrays.fill(lastSeen, -1);

    for (int i = 0; i < s.length(); ++i) {
      final int c = s.charAt(i) - 'A';
      final int currentCount = i - lastSeen[c];
      count = count - lastCount[c] + currentCount;
      lastCount[c] = currentCount;
      lastSeen[c] = i;
      ans += count;
    }

    return ans;
  }
}
