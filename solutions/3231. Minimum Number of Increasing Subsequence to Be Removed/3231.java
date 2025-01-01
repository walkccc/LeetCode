class Solution {
  public int minOperations(int[] nums) {
    // The length of the longest non-increasing subsequence is equal to the
    // number of strictly increasing subsequences needed to cover the entire
    // array. This is because any number in the non-increasing subsequence must
    // use one number from each of the strictly increasing subsequences. e.g.,
    // [4, 3, 1, 2] has 3 strictly increasing subsequences: [4], [3], and [1,
    // 2]. The longest non-increasing subsequences are [4, 3, 1] or [4, 3, 2].
    int[] reversedNums = new int[nums.length];
    for (int i = 0; i < nums.length; ++i)
      reversedNums[i] = nums[nums.length - 1 - i];
    return lengthOfLIS(reversedNums);
  }

  // Similar to 300. Longest Increasing Subsequence
  private int lengthOfLIS(int[] nums) {
    // tails[i] := the minimum tail of all the increasing subsequences having
    // length i + 1
    List<Integer> tails = new ArrayList<>();

    for (final int num : nums)
      if (tails.isEmpty() || num >= tails.get(tails.size() - 1))
        tails.add(num);
      else
        tails.set(firstGreater(tails, num), num);

    return tails.size();
  }

  private int firstGreater(List<Integer> A, int target) {
    int l = 0;
    int r = A.size();
    while (l < r) {
      final int m = (l + r) / 2;
      if (A.get(m) > target)
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
}
