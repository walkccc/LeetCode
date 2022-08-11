class Solution {
  public int minMoves(int[] nums, int k) {
    List<Integer> ones = new ArrayList<>();

    for (int i = 0; i < nums.length; ++i)
      if (nums[i] == 1)
        ones.add(i);

    final int median = ones.get(getMedIndex(0, k));
    int moves = 0;
    for (int i = 0; i < k; ++i)
      moves += Math.abs(ones.get(i) - median);

    int ans = moves;

    for (int i = 1; i <= ones.size() - k; ++i) {
      final int oldMedianIndex = ones.get(getMedIndex(i - 1, k));
      final int newMedianIndex = ones.get(getMedIndex(i, k));
      if (k % 2 == 1)
        moves += newMedianIndex - oldMedianIndex;
      moves -= newMedianIndex - ones.get(i - 1);
      moves += ones.get(i + k - 1) - newMedianIndex;
      ans = Math.min(ans, moves);
    }

    return ans - nThSum((k - 1) / 2) - nThSum(k / 2);
  }

  // return median index of [i..i + k)
  private int getMedIndex(int i, int k) {
    return (i + (i + k - 1)) / 2;
  }

  // return 1 + 2 + ... + n
  private int nThSum(int n) {
    return n * (n + 1) / 2;
  }
}
