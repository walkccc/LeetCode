class Solution {
  public int[] divisibilityArray(String word, int m) {
    int[] ans = new int[word.length()];
    long prevRemainder = 0;

    for (int i = 0; i < word.length(); ++i) {
      final long remainder = (prevRemainder * 10 + (word.charAt(i) - '0')) % m;
      ans[i] = remainder == 0 ? 1 : 0;
      prevRemainder = remainder;
    }

    return ans;
  }
}
