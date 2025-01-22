class Solution {
  public int minAnagramLength(String s) {
    final int n = s.length();
    for (int k = 1; k <= n; ++k)
      if (n % k == 0 && canFormAnagram(s, k))
        return k;
    return n;
  }

  // Returns true if we can concatenate an anagram of length k to s.
  private boolean canFormAnagram(String s, int k) {
    final int n = s.length();
    int[] anagramCount = new int[26];
    int[] runningCount = new int[26];
    for (int i = 0; i < k; ++i)
      ++anagramCount[s.charAt(i) - 'a'];
    for (int i = k; i < n; ++i) {
      ++runningCount[s.charAt(i) - 'a'];
      if (i % k == k - 1) {
        if (!Arrays.equals(runningCount, anagramCount))
          return false;
        Arrays.fill(runningCount, 0);
      }
    }
    return true;
  }
}
