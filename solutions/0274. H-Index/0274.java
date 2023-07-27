class Solution {
  public int hIndex(int[] citations) {
    final int n = citations.length;
    int accumulate = 0;
    int[] count = new int[n + 1];

    for (final int citation : citations)
      ++count[Math.min(citation, n)];

    // To find the largeset h-index, loop from back to front
    // I is the candidate h-index
    for (int i = n; i >= 0; --i) {
      accumulate += count[i];
      if (accumulate >= i)
        return i;
    }

    throw new IllegalArgumentException();
  }
}
