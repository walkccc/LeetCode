class Solution {
  public int minDeletions(String s) {
    int ans = 0;
    int[] count = new int[26];
    Set<Integer> usedFreq = new HashSet<>();

    for (final char c : s.toCharArray())
      ++count[c - 'a'];

    for (int freq : count) {
      while (freq > 0 && usedFreq.contains(freq)) {
        --freq; // Delete ('a' + i).
        ++ans;
      }
      usedFreq.add(freq);
    }

    return ans;
  }
}
