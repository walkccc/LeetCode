class Solution {
  public int maxEnvelopes(int[][] envelopes) {
    Arrays.sort(envelopes, Comparator.comparingInt((int[] envelope) -> envelope[0])
                               .thenComparingInt((int[] envelope) -> - envelope[1]));
    return lengthOfLIS(envelopes);
  }

  // Similar to 300. Longest Increasing Subsequence
  private int lengthOfLIS(int[][] envelopes) {
    // tails[i] := the minimum tail of all the increasing subsequences having
    // length i + 1
    List<Integer> tails = new ArrayList<>();

    for (final int[] envelope : envelopes) {
      final int h = envelope[1];
      if (tails.isEmpty() || h > tails.get(tails.size() - 1))
        tails.add(h);
      else
        tails.set(firstGreaterEqual(tails, h), h);
    }

    return tails.size();
  }

  private int firstGreaterEqual(List<Integer> arr, int target) {
    final int i = Collections.binarySearch(arr, target);
    return i < 0 ? -i - 1 : i;
  }
}
