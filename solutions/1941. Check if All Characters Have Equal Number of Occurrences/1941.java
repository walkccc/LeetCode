class Solution {
  public boolean areOccurrencesEqual(String s) {
    int[] count = new int[26];
    for (final char c : s.toCharArray())
      ++count[c - 'a'];
    return equalFreq(count, count[s.charAt(0) - 'a']);
  }

  private boolean equalFreq(int[] count, int theFreq) {
    return Arrays.stream(count).allMatch(freq -> freq == 0 || freq == theFreq);
  }
}
