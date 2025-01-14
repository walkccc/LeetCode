class Solution {
  public String getSmallestString(int n, int k) {
    StringBuilder sb = new StringBuilder();

    for (int i = 0; i < n; ++i) {
      final int remainingLetters = n - 1 - i;
      final int rank = Math.max(1, k - remainingLetters * 26);
      sb.append((char) ('a' + rank - 1));
      k -= rank;
    }

    return sb.toString();
  }
}
